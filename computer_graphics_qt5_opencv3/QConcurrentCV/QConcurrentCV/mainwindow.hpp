#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QFileInfoList>
#include <QDir>
#include <QFileDialog>
#include <opencv2/opencv.hpp>

namespace Ui {

class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_loopBtn_pressed();

    void on_concurrentBtn_pressed();

private:
    Ui::MainWindow *ui;
    QFileInfoList getImagesInFolder();
};
        void addDateTime(QFileInfo &info);

#endif // MAINWINDOW_HPP
