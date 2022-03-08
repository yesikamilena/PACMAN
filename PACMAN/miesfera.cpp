#include "miesfera.h"

miesfera::miesfera()
{
    vy=7;
}

QRectF miesfera::boundingRect() const
{
    return QRectF(0,0,3,3);//Posición inicial de las bolas; x,y,tamaño en x y tamaño en y.
}

void miesfera::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::white);
    painter->drawEllipse(boundingRect());
    //QPixmap pixmap;
    //pixmap.load(":/Imagenes/pokebola.png");
    //painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void miesfera::mover()
{
    setPos(x(),y()+vy);
}

void miesfera::choque()
{
    vy=-vy/1.3;
}
