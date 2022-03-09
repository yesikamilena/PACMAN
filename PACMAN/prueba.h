#ifndef PRUEBA_H
#define PRUEBA_H

#include <QGraphicsItem>
#include <QPainter>

class prueba :  public QGraphicsItem
{
public:
    prueba();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mover();
    void choque();
    int vy;
};

#endif // PRUEBA_H
