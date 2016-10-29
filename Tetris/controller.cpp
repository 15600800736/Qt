
//controller.cpp
#include <QKeyEvent>
#include <QMessageBox>

#include "mainscene.h"
#include "controller.h"
#include "teris.h"
#include "time.h"
#include "map.h"
namespace Teris
{
Controller::Controller(QObject *parent):
    QObject(parent),
    _mainScene(new MainScene(this)),
     _map(new GameMap()),
    _view(new QGraphicsView(_map)),
    _teris(new Teris(0,-0.5*mapLength+2*blockWidth,15,_map))
{
    _view->setScene(_mainScene);
    _view->resize(_mainScene->width(),_mainScene->height());
    _view->show();
}

void Controller::startGame()
{
    _view->hide();
    _view->setScene(_map);
    _view->resize(_map->width(),_map->height());
    _view->show();
    _map->installEventFilter(this);
    _timer.start(1);
    connect(&_timer,SIGNAL(timeout()),_map,SLOT(advance()));
    connect(_teris,SIGNAL(gameOver()),this,SLOT(gameOver()));
    qsrand((unsigned int)time(0));
    _teris->reset(qrand()&7);
    _map->addItem(_teris);
    _map->setBackgroundBrush(Qt::black);
}
bool Controller::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == _map)
    {
        _map->update(_map->sceneRect());
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
            case Qt::Key_Up:
                _teris->setAction(Teris::TURN);
                break;
            case Qt::Key_Down:
                _teris->setAction(Teris::DOWN);
                break;
            default:
                break;
            }
            return true;
        }
    }
    else
    {
        return QObject::eventFilter(watched,event);
    }
}
void Controller::gameOver()
{
    disconnect(&_timer,SIGNAL(timeout()),_map,SLOT(advance()));
    if(QMessageBox::question(_view,QString("Game Over"),QString("是否重新开始游戏？"),QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes)
    {
        _map->removeAll();
        _teris = new Teris(0,-0.5*mapLength+2*blockWidth,15,_map);
        _map->addItem(_teris);
        connect(&_timer,SIGNAL(timeout()),_map,SLOT(advance()));
    }
    else
    {
        exit(0);
    }
}
void Controller::pause()
{
    disconnect(&_timer,SIGNAL(timeout()),_map,SLOT(advance()));
}
void Controller::resume()
{

}
Controller::~Controller()
{
    delete _teris;
    delete _view;
    delete _map;
}
}
