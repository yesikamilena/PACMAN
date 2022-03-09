#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class sprite : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit sprite(QObject *parent = nullptr);
    QTimer *timer;
    QPixmap *pixmap;

    float filas=0, columnas=0; //Para iterar sobre la imágen

    float ancho;
    float alto;

    QRectF boundingRect() const;  //() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
    void actualizacion();
};

#endif // SPRITE_H
