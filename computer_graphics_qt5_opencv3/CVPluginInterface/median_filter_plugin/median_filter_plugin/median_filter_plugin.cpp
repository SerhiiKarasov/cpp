#include "median_filter_plugin.hpp"


Median_filter_plugin::Median_filter_plugin()
{
}

Median_filter_plugin::~Median_filter_plugin()
{

}

QString Median_filter_plugin::description()
{
    return "This plugin applies median blur filters to any image";
}

void Median_filter_plugin::processImage(const cv::Mat &inputImage, cv::Mat &outputImage)
{
    cv::medianBlur(inputImage, outputImage, 5);
}
