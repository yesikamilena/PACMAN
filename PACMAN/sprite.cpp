#include "sprite.h"

sprite::sprite(QObject *parent) : QObject(parent)
{
    timer=new QTimer();

    filas=0;
    columnas=0;

    pixmap= new QPixmap(":/imagen/pacman7.png");

    ancho=15;   //
    alto=15;    //5cm=15pc

    timer->start(250);  //Tiempo en milisegundos de iteración de las imágenes.

    connect(timer,&QTimer::timeout,this,&sprite::actualizacion);

}

QRectF sprite::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap, columnas, 0, ancho, alto);     //El último parámetro es la fila!!
}

void sprite::actualizacion()
{
    columnas+=16;
    if(columnas>=90){
        columnas=0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}
