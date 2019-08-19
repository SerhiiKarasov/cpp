#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setAcceptDrops(true);
    ui->graphicsView->setAcceptDrops(false);
    ui->graphicsView->setScene(&scene);


    QGraphicsRectItem *item =
    new QGraphicsRectItem(0,
                          0,
                          100,
                          100);
    item->setPos(50,400);
    scene.addItem(item);
    QGraphicsRectItem *parentItem =
        new QGraphicsRectItem(0,
                              0,
                              320,
                              240);
    parentItem->setPos(300, 50);
    scene.addItem(parentItem);

    QGraphicsRectItem *childItem1 =
        new QGraphicsRectItem(0,
                              0,
                              50,
                              50,
                              parentItem);
    childItem1->setPos(50,50);
    QGraphicsRectItem *childItem2 =
        new QGraphicsRectItem(0,
                              0,
                              75,
                              75,
                              parentItem);
    childItem2->setPos(150,75);

    qDebug() << item->mapFromItem(childItem1, 0,0);
    qDebug() << item->mapToItem(childItem1, 0,0);
    qDebug() << childItem1->mapFromScene(0,0);
    qDebug() << childItem1->mapToScene(0,0);
    qDebug() << childItem2->mapFromParent(0,0);
    qDebug() << childItem2->mapToParent(0,0);
    qDebug() << item->mapRectFromItem(childItem1,
                                  childItem1->rect());
    qDebug() << item->mapRectToItem(childItem1,
                                childItem1->rect());
    qDebug() << childItem1->mapRectFromScene(0,0, 25, 25);
    qDebug() << childItem1->mapRectToScene(0,0, 25, 25);
    qDebug() << childItem2->mapRectFromParent(0,0, 30, 30);
    qDebug() << childItem2->mapRectToParent(0,0, 25, 25);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    QStringList acceptedFileTypes;
    acceptedFileTypes.append("jpg");
    acceptedFileTypes.append("png");
    acceptedFileTypes.append("bmp");

    if (event->mimeData()->hasUrls() &&
            event->mimeData()->urls().count() == 1)
    {

        QFileInfo file(event->mimeData()->urls().at(0).toLocalFile());
        if(acceptedFileTypes.contains(file.suffix().toLower()))
        {
            event->acceptProposedAction();
        }
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    QPoint viewPos = ui->graphicsView->mapFromParent(event->pos());
    QPointF sceneDropPos = ui->graphicsView->mapToScene(viewPos);

    QFileInfo file(event
                   ->mimeData()
                   ->urls()
                   .at(0)
                   .toLocalFile());
    QPixmap pixmap;
    if(pixmap.load(file
                   .absoluteFilePath()))
    {
        QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pixmap);
        item->setPos(sceneDropPos);
        item->setFlag(QGraphicsItem::ItemIsSelectable);
        item->setAcceptedMouseButtons(Qt::LeftButton);
        scene.clear();
        scene.addItem(item);
        qDebug() << scene.items().count();
    }
    else
    {
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("The image file cannot be read!"));
    }
}
