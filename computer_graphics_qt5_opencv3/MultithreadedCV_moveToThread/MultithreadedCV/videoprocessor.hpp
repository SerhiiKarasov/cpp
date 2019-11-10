#ifndef VIDEOPROCESSOR_HPP
#define VIDEOPROCESSOR_HPP

#include <QObject>
#include <QThread>
#include <QPixmap>
#include "opencv2/opencv.hpp"

class VideoProcessor : public QObject
{
    Q_OBJECT
public:
    explicit VideoProcessor(QObject *parent = nullptr);

signals:
  void inDisplay(QPixmap pixmap);
  void outDisplay(QPixmap pixmap);

public slots:
  void startVideo();
  void stopVideo();

private:
  bool stopped;
};

#endif // VIDEOPROCESSOR_HPP
