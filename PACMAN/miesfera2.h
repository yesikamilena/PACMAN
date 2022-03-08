#ifndef MIESFERA2_H
#define MIESFERA2_H


#include <QGraphicsItem>
#include <QPainter>

class miesfera2 : public QGraphicsItem
{
public:
    miesfera2();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mover();
    void choque();
    int vy;
};

#endif // MIESFERA2_H
