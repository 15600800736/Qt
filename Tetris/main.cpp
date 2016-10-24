#include "mainwindow.h"
#include <QApplication>
#include "teris.h"
#include <QGraphicsScene>
#include <QGraphicsView>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene* gameScene = new QGraphicsScene();
    Teris::Teris* L = new Teris::Teris(100,100,Teris::Teris::L,100,NULL);
    Teris::Teris* RL = new Teris::Teris(100,500,Teris::Teris::RL,100,NULL);
    Teris::Teris* I = new Teris::Teris(100,300,Teris::Teris::I,100,NULL);
    Teris::Teris* T = new Teris::Teris(300,100,Teris::Teris::T,100,NULL);
    Teris::Teris* Z = new Teris::Teris(300,300,Teris::Teris::Z,100,NULL);
    Teris::Teris* RZ = new Teris::Teris(300,500,Teris::Teris::RZ,100,NULL);
    Teris::Teris* O = new Teris::Teris(500,100,Teris::Teris::O,100,NULL);
    gameScene->addItem(L);
    gameScene->addItem(RL);
    gameScene->addItem(I);
    gameScene->addItem(T);
    gameScene->addItem(Z);
    gameScene->addItem(RZ);
    gameScene->addItem(O);
    QGraphicsView* gameView = new QGraphicsView(gameScene);
    gameView->show();
    return a.exec();
}
