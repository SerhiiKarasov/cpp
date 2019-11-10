#ifndef QCUSTOMGRAPHICSEFFECT_HPP
#define QCUSTOMGRAPHICSEFFECT_HPP

#include <QObject>
#include <QGraphicsEffect>
#include <QPainter>
class QCustomGraphicsEffect : public QGraphicsEffect{
    Q_OBJECT
public:
    explicit QCustomGraphicsEffect(QObject *parent = nullptr);

signals:

public slots:

protected:

  void draw(QPainter *painter);
};

#endif // QCUSTOMGRAPHICSEFFECT_HPP
