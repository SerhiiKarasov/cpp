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
