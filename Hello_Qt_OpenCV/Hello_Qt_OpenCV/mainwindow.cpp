#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadSettings();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// connecting slots by name
// qobject name = input_button_browse
// event/signal name = pressed
void MainWindow::on_input_button_browse_pressed()
{
    // QFileDialog is some ui to select file or folder on computer
    // QDir and QFile kind of std::filesystems
    QString fileName = QFileDialog::getOpenFileName(this, "Open Input Image", QDir::currentPath(), "Images (*.jpg *.png *.bmp)");
    if (QFile::exists(fileName))
    {
        // ui is an object to access any element on main window
        ui->inputLineEdit->setText(fileName);
    }
}


void MainWindow::on_output_button_browse_pressed()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select Output Image", QDir::currentPath(), "Images (*.jpg *.png *.bmp)");

    if(!fileName.isEmpty())
    {
        ui->OutputLineEdit->setText(fileName);
        using namespace cv;
        Mat inpImg;
        Mat outImg;
        inpImg = imread(ui->inputLineEdit->text().toStdString());
        if(ui->mblur_radiobutton->isChecked())
        {
            cv::medianBlur(inpImg, outImg, 5);
        }else if(ui->gblur_radiobutton->isChecked())
        {
            cv::GaussianBlur(inpImg, outImg, Size(5,5), 1.25);
        }
        imwrite(fileName.toStdString(), outImg);
        if(ui->display_image_checkbox->isChecked())
        {
            imshow("Output Image", outImg);
        }
    }
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    int result = QMessageBox::warning(this, "Exit", "Are sure you want to close this program?", QMessageBox::Yes, QMessageBox::No);
    if(result == QMessageBox::Yes)
    {
        saveSettings();
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void MainWindow::loadSettings()
{
    QSettings settings("SK", "OpenCV_QT", this);
    ui->inputLineEdit->setText(settings.value("inputLineEdit", "").toString());
    ui->OutputLineEdit->setText(settings.value("OutputLineEdit", "").toString());
    ui->gblur_radiobutton->setChecked(settings.value("gblur_radiobutton").toBool());
    ui->mblur_radiobutton->setChecked(settings.value("mblur_radiobutton").toBool());
    ui->display_image_checkbox->setChecked(settings.value("display_image_checkbox").toBool());
}

void MainWindow::saveSettings()
{
    QSettings settings("SK", "OpenCV_QT", this);
    settings.setValue("inputLineEdit", ui->inputLineEdit->text());
    settings.setValue("OutputLineEdit", ui->OutputLineEdit->text());
    settings.setValue("gblur_radiobutton", ui->gblur_radiobutton->isChecked());
    settings.setValue("mblur_radiobutton", ui->mblur_radiobutton->isChecked());
    settings.setValue("display_image_checkbox", ui->display_image_checkbox->isChecked());
}
