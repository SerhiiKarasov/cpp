#ifndef MEDIAN_FILTER_PLUGIN_HPP
#define MEDIAN_FILTER_PLUGIN_HPP

#include "median_filter_plugin_global.hpp"
#include "cvpluggininterface.hpp"

class MEDIAN_FILTER_PLUGINSHARED_EXPORT Median_filter_plugin:
        public QObject, public CvPlugginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.sergio.cvpluggininterface")
    Q_INTERFACES(CvPlugginInterface)

public:
    Median_filter_plugin();
    ~Median_filter_plugin();
    QString description();
    void processImage(const cv::Mat &inputImage, cv::Mat &outputImage);
};

#endif // MEDIAN_FILTER_PLUGIN_HPP
