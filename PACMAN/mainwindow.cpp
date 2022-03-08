#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene=new QGraphicsScene(0,0,500,400);
    ui->graphicsView->setScene(scene);

    puntuacion = 0;
    moverIx1=false;
    moverDx1=false;
    moverUy1=false;
    moverDy1=false;
    mover2=false;
    dibuja=false;
    unos=0;


    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/imagen/Fondo.jpg")));

    timer=new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(animar()));
    connect(this,SIGNAL(aviso(int)),this,SLOT(aumentarPunt()));

    timer->start(33);
/*
    //Superiores
    barra=new QGraphicsRectItem(10,10,60,5);
    scene->addItem(barra);
    barra->setPos(0,0);
    barra->setBrush(Qt::darkBlue);

    barra=new QGraphicsRectItem(20,20,60,5);
    scene->addItem(barra);
    barra->setPos(0,0);
    barra->setBrush(Qt::darkBlue);


    //Izquierda
    barra2=new QGraphicsRectItem(10,10,5,60);
    scene->addItem(barra2);
    barra2->setPos(0,0);
    barra2->setBrush(Qt::darkBlue);

    barra2=new QGraphicsRectItem(20,20,5,60);
    scene->addItem(barra2);
    barra2->setPos(0,0);
    barra2->setBrush(Qt::darkBlue);
*/
    for(k=0; k<13; k++){     //Filas
        for(l=0; l<60; l++){    //Columnas

    /*        if(matriz[k][l]==0){
                if(unos>1){
                    dibuja=true;    //Si ya no recibe un 1 en matriz[k][l], y unos es de 2 o más, dibuje.
                }
            }*/

            if(matriz[k][l]==3){
                bola = new miesfera();
                scene->addItem(bola);
                bola->setPos((l+1)*5,(k+1)*5);
      /*          if(unos>1){
                    dibuja=true;    //Si ya no recibe un 1 en matriz[k][l], y unos es de 2 o más, dibuje.
                }*/
            }

            if(matriz[k][l]==4){
                bola_grande = new miesfera2();
                scene->addItem(bola_grande);
                bola_grande->setPos((l+1)*5,(k+1)*5);
          /*      if(unos>1){
                    dibuja=true;        //Si ya no recibe un 1 en matriz[k][l], y unos es de 2 o más, dibuje.
                }*/
            }

            if(matriz[k][l]!=1){
                if(unos>1){
                  dibuja=true;        //Si ya no recibe un 1 en matriz[k][l], y unos es de 2 o más, dibuje.
                }
                else {
                    unos=0;
                }
            }


            if(matriz[k][l]==1){
                if(unos==0){
                    k_inicio=k+1;       //Da las posiciones iniciales, porque unos no había recibido nada aún.
                    l_inicio=l+1;
                }
                unos++;
            }


            if(dibuja==true || unos==60){       //Si ya tiene la bandera para dibujar o si unos llegó a su límite, dibuje la fila

                barra=new QGraphicsRectItem(l_inicio*5,k_inicio*5,(unos)*5,5);
                scene->addItem(barra);
                barra->setPos(0,0);
                barra->setBrush(Qt::darkBlue);

                k_inicio=0;
                l_inicio=0;
                unos=0;
                dibuja=false;
            }
        }
            k_inicio=0;
            l_inicio=0;
            unos=0;
            dibuja=false;
        }


    //Dibujo de las líneas verticales

    for(l=0; l<60; l++){     //Columnas
        for(k=0; k<13; k++){    //Filas

            if(matriz[k][l]!=1){
                if(unos>1){
                  dibuja=true;        //Si ya no recibe un 1 en matriz[k][l], y unos es de 2 o más, dibuje.
                }
                else {
                    unos=0;
                }
            }


            if(matriz[k][l]==1){
                if(unos==0){
                    k_inicio=k+1;       //Da las posiciones iniciales, porque unos no había recibido nada aún.
                    l_inicio=l+1;
                }
                unos++;
            }

            if(dibuja==true || unos==13){       //Si ya tiene la bandera para dibujar o si unos llegó a su límite, dibuje la fila

                barra=new QGraphicsRectItem(l_inicio*5,k_inicio*5,5,(unos)*5);
                scene->addItem(barra);
                barra->setPos(0,0);
                barra->setBrush(Qt::darkBlue);

                k_inicio=0;
                l_inicio=0;
                unos=0;
                dibuja=false;
            }

}


        k_inicio=0;
        l_inicio=0;
        unos=0;
        dibuja=false;

    }



  //  bola = new miesfera();
   // scene->addItem(bola);
   // bola->setPos(30,30);

  //  l1=new QGraphicsLineItem(0,0,500,20);
   // l2=new QGraphicsLineItem(0,0,0,400);
 //   l3=new QGraphicsLineItem(500,0,500,400);
  //  l4=new QGraphicsLineItem(0,400,500,400);
   // l5=new QLineF(0,0,500,0);
   // scene->addItem(l1);
   // scene->addItem(l2);
 //   scene->addItem(l3);
  //  scene->addItem(l4);*/
    //l5->setBrush(Qt::white);

    //barra->setBrush(Qt::white);
    //barra->setBrush(Qt::white);
    //barra->setBrush(Qt::white);

    bola = new miesfera();
    scene->addItem(bola);
    bola->setPos(200,350);

    //scene->destroyed()

}


MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}


void MainWindow::animar()
{
    if(moverIx1 && barra->x()>30)
    {
        barra->setPos(barra->x()-2,barra->y());
    }
    if(moverDx1)
    {
        barra->setPos(barra->x()+2,barra->y());
    }
    if(moverUy1)
    {
        barra->setPos(barra->x(),barra->y()-2);
    }
    if(moverDy1)
    {
        barra->setPos(barra->x(),barra->y()+2);
    }
    if(mover2)
    {
        barra2->setPos(barra2->x()-2,barra2->y());
    }

 //   if(barra->collidesWithItem(l2) || barra->collidesWithItem(l3))
 //   {
 //       moverIx1=false;
        /*if(bola->isVisible()){
            bola->hide();
            //delete bola;
        }*/

   // }
    if(barra->collidesWithItem(bola))
    {
        if(bola->isVisible()){
            bola->hide();
            emit aviso(9);
            //delete bola;
        }

    }

    /*for(int i=0; i<bolas.length();i++)
    {
        bolas.at(i)->mover();
        if(!bolas.at(i)->collidingItems().empty())
        {
            bolas.at(i)->choque();
        }
    }*/
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        moverIx1=true;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverDx1=true;
    }
    else if(ev->key()==Qt::Key_W)
    {
        moverUy1=true;
    }
    else if(ev->key()==Qt::Key_Z)
    {
        moverDy1=true;
    }
    else if(ev->key()==Qt::Key_D)
    {
        mover2=true;
    }
    /*else if(ev->key()==Qt::Key_X)
    {
        delete bola;
    }*/
}

void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        moverIx1=false;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverDx1=false;
    }
    else if(ev->key()==Qt::Key_W)
    {
        moverUy1=false;
    }
    else if(ev->key()==Qt::Key_Z)
    {
        moverDy1=false;
    }
    else if(ev->key()==Qt::Key_D)
    {
        mover2=false;
    }
}

void MainWindow::aumentarPunt()
{
    puntuacion += 5;
    ui->lcdNumber->display(puntuacion);
    std::cout<<puntuacion<<std::endl;
}



/*void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    bolas.append(new Bola());
    scene->addItem(bolas.last());
    bolas.last()->setPos(ev->x()-83,ev->y()-83);
}*/

