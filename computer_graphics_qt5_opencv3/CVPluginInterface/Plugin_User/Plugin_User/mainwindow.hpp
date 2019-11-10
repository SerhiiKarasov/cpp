#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QDir>
#include <QMessageBox>
#include <QPluginLoader>
#include <QFileInfoList>
#include "opencv2/opencv.hpp"
#include "cvpluggininterface.hpp"
#include <QFileDialog>
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
    void on_inputImgButton_pressed();

    void on_helpButton_pressed();

    void on_filterButton_pressed();

private:
    Ui::MainWindow *ui;
    void getPluginsList();
};

#endif // MAINWINDOW_HPP
