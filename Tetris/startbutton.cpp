
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
void StartButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    QLinearGradient line;
    line.setStart(boundingRect().topLeft());
    line.setFinalStop(boundingRect().bottomRight());
    line.setColorAt(0,Qt::white);
    line.setColorAt(0.8,Qt::blue);
    line.setColorAt(1,Qt::black);
    painter->setBrush(QBrush(line));
    painter->drawRoundRect(boundingRect(),10,10);
    painter->restore();
}
void StartButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}
void StartButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    _controller->startGame();
}
}
