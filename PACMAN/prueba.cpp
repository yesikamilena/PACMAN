#include "prueba.h"

prueba::prueba()
{
    vy=7;
}


QRectF prueba::boundingRect() const
{
    return QRectF(0,0,3,3);//Posición inicial de las bolas; x,y,tamaño en x y tamaño en y.
}

void prueba::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::white);
    //painter->drawEllipse(boundingRect());
    QPixmap pixmap;
    pixmap.load(":/Imagenes/pacman1.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void prueba::mover()
{
    setPos(x(),y()+vy);
}

void prueba::choque()
{
    vy=-vy/1.3;
}
