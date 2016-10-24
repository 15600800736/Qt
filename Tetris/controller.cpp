
//controller.cpp
#include <QKeyEvent>

#include "controller.h"
#include "teris.h"
#include "time.h"
#include "map.h"
namespace Teris
{
Controller::Controller(QObject *parent):
    QObject(parent),
    _map(new GameMap()),
    _teris(new Teris(0,-0.5*mapLength+2*blockWidth,50,_map)),
    _scene(new QGraphicsScene(this)),
    _view(new QGraphicsView(_scene))
{
    _view->setScene(_scene);
    _view->resize(mapWidth,mapLength);
    _view->show();
}

void Controller::startGame()
{
    _timer.start(1000/33);
    connect(&_timer,SIGNAL(timeout()),_scene,SLOT(advance()));
    qsrand((unsigned)time(0));
    int itype = qrand() % 7;
    Teris::TerisType type;
    switch(itype)
    {
    case 0:
        type = Teris::L;
        break;
    case 1:
        type = Teris::RL;
        break;
    case 2:
        type = Teris::Z;
        break;
    case 3:
        type = Teris::RZ;
        break;
    case 4:
        type = Teris::O;
        break;
    case 5:
        type = Teris::I;
        break;
    case 6:
        type = Teris::T;
        break;
    default:
        break;
    }
    _teris->setType(type);
    _teris->reset();
    _scene->addItem(_teris);
    _scene->addItem(_map);
    _teris->setZValue(1);
    _map->setZValue(0);
    _scene->setBackgroundBrush(Qt::black);
}
void Controller::eventFilter(QObject *watched, QEvent *event)
{
    update(_map->boundingRect());
    if(event == QEvent::KeyPress)
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        if(keyEvent->key() == Qt::Key_Left)
        {

        }
    }
    else
    {
        return QObject::eventFilter(watched,event);
    }
}

Controller::~Controller()
{
    delete _teris;
    delete _scene;
    delete _view;
    delete _map;
}
}
