#ifndef QENHANCEDGRAPHICSVIEW_HPP
#define QENHANCEDGRAPHICSVIEW_HPP

#include <QWidget>
#include <QGraphicsView>

class QEnhancedGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit QEnhancedGraphicsView(QWidget *parent = nullptr);

signals:

public slots:

private slots:
  void clearAll(bool);
  void clearSelected(bool);
  void noEffect(bool);
  void blurEffect(bool);
  void dropShadowEffect(bool);
  void colorizeEffect(bool);
  void customEffect(bool);

protected:
  void wheelEvent(QWheelEvent *event);
  void mouseEvent(QMouseEvent *event);

  void mousePressEvent(QMouseEvent *event);

private:
   QPointF sceneMousePos;

};

#endif // QENHANCEDGRAPHICSVIEW_HPP
