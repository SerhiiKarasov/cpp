#ifndef QIMAGEPROCESSOR_HPP
#define QIMAGEPROCESSOR_HPP

#include <QObject>
#include <QImage>
#include "opencv2/opencv.hpp"

class QImageProcessor : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE void processImage(const QString &path);
    explicit QImageProcessor(QObject *parent = nullptr);

signals:
        void imageProcessed(const QImage &image);
public slots:
};

#endif // QIMAGEPROCESSOR_HPP
