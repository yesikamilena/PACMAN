#ifndef LINEA_H
#define LINEA_H

#include <QGraphicsItem>
#include <QPainter>

class linea : public QGraphicsItem
{
public:
    linea();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mover();
    void choque();
    int vy;
};

#endif // LINEA_H
