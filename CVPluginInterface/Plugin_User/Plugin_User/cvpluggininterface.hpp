#ifndef CVPLUGGININTERFACE_HPP
#define CVPLUGGININTERFACE_HPP

#include <QObject>
#include <QString>
#include "opencv2/opencv.hpp"

class CvPlugginInterface
{
    public:
    virtual ~CvPlugginInterface(){}
    virtual QString description() = 0;
    virtual void processImage(const cv::Mat &inputImage, cv::Mat &outputImage) =0;
};
#define CVPLUGININTERFACE_IID "com.sergio.cvplugininterface"
Q_DECLARE_INTERFACE(CvPlugginInterface, CVPLUGININTERFACE_IID)
#endif // CVPLUGGININTERFACE_HPP
