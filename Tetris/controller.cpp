
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
    _scene->installEventFilter(this);
    _view->setScene(_scene);
    _view->resize(mapWidth,mapLength);
    _view->show();
}

void Controller::startGame()
{
    //tmp
    Teris* teris_tmp = new Teris(0,mapLength,50,_map);
    teris_tmp->setAction(Teris::STOP);
    _scene->addItem(teris_tmp);
    //tmp
    _timer.start(5);
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
bool Controller::eventFilter(QObject *watched, QEvent *event)
{
    _map->update(_map->boundingRect());
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        switch(keyEvent->key())
        {
        case Qt::Key_Left:
            _teris->setAction(Teris::LEFT);
            break;
        case Qt::Key_Right:
            _teris->setAction(Teris::RIGHT);
            break;
        case Qt::Key_Enter:
            _teris->setAction(Teris::TURN);
            break;
        case Qt::Key_Down:
            _teris->setAction(Teris::DOWN);
            break;
        case Qt::Key_A:
            _teris->setAction(Teris::STOP);
            break;
        default:
            break;
        }
        return true;
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
