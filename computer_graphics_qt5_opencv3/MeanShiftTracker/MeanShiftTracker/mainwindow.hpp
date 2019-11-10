#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QDebug>
#include "qcvmeanshiftthread.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private:
    QCvMeanShiftThread *meanshift;
    QGraphicsPixmapItem pixmap;

private slots:
    void onRubberBandChanged(QRect rect,
                             QPointF frScn, QPointF toScn);
    void onNewFrame(QPixmap newFrm);
};

#endif // MAINWINDOW_HPP
