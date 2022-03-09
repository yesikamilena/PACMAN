#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QRect Desktop = QApplication::desktop()->screenGeometry();
    x=Desktop.x();
    y=Desktop.y();
    ancho=Desktop.width()-100;
    alto=Desktop.height()-100;

    scene=new QGraphicsScene(0,0,500,400);
    ui->graphicsView->setScene(scene);

    puntuacion = 0;
    moverA=false;
    moverS=false;
    moverD=false;
    moverZ=false;
    //mover2=false;
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
    for(k=0; k<66; k++){     //Filas
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
        for(k=0; k<66; k++){    //Filas

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

            if(dibuja==true || unos==65){       //Si ya tiene la bandera para dibujar o si unos llegó a su límite, dibuje la fila

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

    pacman = new sprite();
    scene->addItem(pacman);
    pacman->setPos(150,247);


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
    int x_matriz=0, y_matriz=0;


    if(moverA)
    {
        x_matriz=pacman->x()-3*5;       //Se multiplica el 2*5 porque cada posición va de a 5.
        y_matriz=pacman->y();

        x_matriz=x_matriz/5;        //Se dividen por 5 porque como cada posición va de a 5, en la matriz sería la posición entre 5.
        y_matriz=y_matriz/5;

        if(matriz[y_matriz][x_matriz]!=1){
            pacman->setPos(pacman->x()-2,pacman->y());  //Izquierda
            pacman->filas=16;
        }
    }

    if(moverD)
    {
        x_matriz=pacman->x()+1*5;       //Se multiplica el 2*5 porque cada posición va de a 5.
        y_matriz=pacman->y();

        x_matriz=x_matriz/5;        //Se dividen por 5 porque como cada posición va de a 5, en la matriz sería la posición entre 5.
        y_matriz=y_matriz/5;

        if(matriz[y_matriz][x_matriz]!=1){
        pacman->setPos(pacman->x()+2,pacman->y());  //Derecha
        pacman->filas=0;
        }
    }
    if(moverS)
    {
        x_matriz=pacman->x();       //Se multiplica el 2*5 porque cada posición va de a 5.
        y_matriz=pacman->y()-3*5;

        x_matriz=x_matriz/5;        //Se dividen por 5 porque como cada posición va de a 5, en la matriz sería la posición entre 5.
        y_matriz=y_matriz/5;

        if(matriz[y_matriz][x_matriz]!=1){
        pacman->setPos(pacman->x(),pacman->y()-2);  //Arriba
        pacman->filas=16*2;
        }
    }

    if(moverZ)
    {
        x_matriz=pacman->x();       //Se multiplica el 2*5 porque cada posición va de a 5.
        y_matriz=pacman->y()+1*5;

        x_matriz=x_matriz/5;        //Se dividen por 5 porque como cada posición va de a 5, en la matriz sería la posición entre 5.
        y_matriz=y_matriz/5;

        if(matriz[y_matriz][x_matriz]!=1){
        pacman->setPos(pacman->x(),pacman->y()+2);  //Abajo
        pacman->filas=16*3;
    }
    }
    /*
    if(mover2)
    {
        pacman->setPos(pacman->x()-2,barra2->y());
    }
    */

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
        moverA=true;

    }
    else if(ev->key()==Qt::Key_S)
    {
        moverS=true;
    }
    else if(ev->key()==Qt::Key_Z)
    {
        moverZ=true;
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverD=true;
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
        moverA=false;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverS=false;
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverD=false;
    }
    else if(ev->key()==Qt::Key_Z)
    {
        moverZ=false;
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

