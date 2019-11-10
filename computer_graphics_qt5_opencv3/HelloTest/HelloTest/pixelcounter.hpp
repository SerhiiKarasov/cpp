#ifndef PIXELCOUNTER_HPP
#define PIXELCOUNTER_HPP

#include <QObject>
#include <QFile>
#include "opencv2/opencv.hpp"

class PixelCounter : public QObject
{
    Q_OBJECT
public:
    explicit PixelCounter(QObject *parent = nullptr);
    int countPixels(QString fname);

signals:

public slots:
};

#endif // PIXELCOUNTER_HPP
