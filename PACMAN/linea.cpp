#include "linea.h"

/*miesfera::miesfera()
{
    vy=7;
}*/

QRectF linea::boundingRect() const
{
    return QRectF(-10,-10,7,7);
}

void linea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::white);
    painter->drawEllipse(boundingRect());
    //QPixmap pixmap;
    //pixmap.load(":/Imagenes/pokebola.png");
    //painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void linea::mover()
{
    setPos(x(),y()+vy);
}

void linea::choque()
{
    vy=-vy/1.3;
}
