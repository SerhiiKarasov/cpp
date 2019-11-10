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
#include <QTranslator>

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
    void on_actionUkrainian_triggered();
    void on_actionRussian_triggered();
    void on_actionEnglish_triggered();

private:
    Ui::MainWindow *ui;
    void loadSettings();
    void saveSettings();
    QTranslator *uaTranslator;
    QTranslator *ruTranslator;

protected:
    void closeEvent(QCloseEvent *event);
    void changeEvent(QEvent *event);
};

#endif // MAINWINDOW_H
