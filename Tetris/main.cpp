
//main.cpp
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "mainwindow.h"
#include "teris.h"
#include "map.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene* gameScene = new QGraphicsScene();
    Teris::GameMap* map = new Teris::GameMap();
    Teris::Teris* L = new Teris::Teris(0,-0.5*mapLength+20,Teris::Teris::L,100,map);
    Teris::Teris* RL = new Teris::Teris(0,-0.5*mapLength+2*40,Teris::Teris::RL,100,map);
    Teris::Teris* I = new Teris::Teris(0,-0.5*mapLength+3*40,Teris::Teris::I,100,map);
    Teris::Teris* T = new Teris::Teris(0,-0.5*mapLength+4*40,Teris::Teris::T,100,map);
    Teris::Teris* Z = new Teris::Teris(0,-0.5*mapLength+5*40,Teris::Teris::Z,100,map);
    Teris::Teris* RZ = new Teris::Teris(0,-0.5*mapLength+6*40,Teris::Teris::RZ,100,map);
    Teris::Teris* O = new Teris::Teris(0,-0.5*mapLength+7*40,Teris::Teris::O,100,map);
    gameScene->addItem(map);
    gameScene->addItem(L);
    gameScene->addItem(RL);
    gameScene->addItem(I);
    gameScene->addItem(T);
    gameScene->addItem(Z);
    gameScene->addItem(RZ);
    gameScene->addItem(O);
    QGraphicsView* gameView = new QGraphicsView(gameScene);
    gameView->resize(mapWidth,mapLength);
    gameView->show();
    return a.exec();
}
