#ifndef MIESFERA_H
#define MIESFERA_H

#include <QGraphicsItem>
#include <QPainter>

class miesfera : public QGraphicsItem
{
public:
    miesfera();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mover();
    void choque();
    int vy;
};

#endif // MIESFERA_H
