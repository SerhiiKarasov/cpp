#include <QCoreApplication>
#include "opencv2/opencv.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    using namespace cv;
    Mat image = imread("/home/computer/Coding/ComputerVisionQT5andOpenCV3/QtCvTest/QtCvTest/Screenshot_20190726_011506.png");
    imshow("Output", image);
    return a.exec();
}
