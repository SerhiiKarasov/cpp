#ifndef QBLINKINGWIDGET_HPP
#define QBLINKINGWIDGET_HPP

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>

class QBlinkingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QBlinkingWidget(QWidget *parent = nullptr);

signals:

public slots:
    void onBlink();
protected:
    void paintEvent(QPaintEvent *event);
private:
    QTimer blinkTimer;
    bool blink;
};

#endif // QBLINKINGWIDGET_HPP
