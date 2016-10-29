
//startbutton.cpp
#include <QPainter>

#include "startbutton.h"

namespace Teris
{
StartButton::StartButton(qreal width, qreal height, qreal x, qreal y, Controller *controller):
    MainSceneButton(QString("Start"),width,height,x,y,controller)
{

}
void StartButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();

}
}
