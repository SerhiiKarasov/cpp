#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QCloseEvent>
#include <QMessageBox>
#include <QSettings>
#include "opencv2/opencv.hpp"
#include <QMainWindow>

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
    void on_input_button_browse_pressed();
    void on_output_button_browse_pressed();

private:
    Ui::MainWindow *ui;
    void loadSettings();
    void saveSettings();

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
