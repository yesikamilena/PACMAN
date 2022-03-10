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

    for(k=0; k<66; k++){     //Filas
        for(l=0; l<60; l++){    //Columnas

            /*
            if(matriz[k][l]==3){
                bola = new miesfera();
                scene->addItem(bola);
                bola->setPos((l+1)*5,(k+1)*5);
                }
*/


            if(matriz[k][l]==3){
                bolas[i] = new miesfera();
                scene->addItem(bolas[i]);
                bolas[i]->setPos((l+1)*5,(k+1)*5);
                i++;
                }



            if(matriz[k][l]==4){
                bolas_grandes[j] = new miesfera2();
                scene->addItem(bolas_grandes[j]);
                bolas_grandes[j]->setPos((l+1)*5,(k+1)*5);
                j++;
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

        if(pacman->x()>380 & pacman->y()==220){
            pacman->setPos(0,33*5);  //Derecha
        }

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

    if(pacman->x()>290 && pacman->y()<170){     //Para devolverse a la izquierda.
        pacman->setPos(10,155);
    }

    if(pacman->x()<10 && pacman->y()<170){     //Para devolverse a la derecha. Se toma con x menor a 10 para que no se devuelva cuando antes se haya devuelto a la izquieda.
        pacman->setPos(290,155);
    }


    //Choque con las bolas pequeñas
    for(int o=0; o<244; o++){
        if(pacman->collidesWithItem(bolas[o]))
        {
            if(bolas[o]->isVisible()){
                bolas[o]->hide();
                aumentarPunt();
            }
        }
    }

    //Choque con las bolas grandes
    for(int o=0; o<5; o++){
        if(pacman->collidesWithItem(bolas_grandes[o]))
        {
            if(bolas_grandes[o]->isVisible()){
                bolas_grandes[o]->hide();
                aumentarPunt();
                aumentarPunt();     //Para aumentar el doble de puntos: 5+5=10 puntos
            }
        }
    }
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
