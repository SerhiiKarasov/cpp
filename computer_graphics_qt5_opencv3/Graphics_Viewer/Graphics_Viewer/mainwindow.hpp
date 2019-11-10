#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>


#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPixmap>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QFileInfo>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
};

#endif // MAINWINDOW_HPP
