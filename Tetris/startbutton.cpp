
//startbutton.cpp
#include <QPainter>

#include "startbutton.h"
#include "controller.h"
#include "constants.h"
namespace Teris
{
StartButton::StartButton(qreal width, qreal height, qreal x, qreal y, Controller *controller):
    MainSceneButton(QString("Start"),width,height,x,y,controller)
{

}

void StartButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}
void StartButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    _controller->startGame();
}
}
