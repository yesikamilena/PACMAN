#include "miesfera2.h"

miesfera2::miesfera2()
{
    vy=7;
}

QRectF miesfera2::boundingRect() const
{
    return QRectF(0,0,7,7);//Posición inicial de las bolas; x,y,tamaño en x y tamaño en y.
}

void miesfera2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::white);
    painter->drawEllipse(boundingRect());
    //QPixmap pixmap;
    //pixmap.load(":/Imagenes/pokebola.png");
    //painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void miesfera2::mover()
{
    setPos(x(),y()+vy);
}

void miesfera2::choque()
{
    vy=-vy/1.3;
}
