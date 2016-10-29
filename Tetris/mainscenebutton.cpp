
//mainscenebutton.cpp
#include <QPainter>

#include "mainscenebutton.h"
#include "controller.h"
namespace Teris
{
MainSceneButton::MainSceneButton(QString caption, qreal width, qreal height, qreal x, qreal y, Controller* controller)
{
    setPos(x,y);
    _width = width;
    _height = height;
    _caption = caption;
    _controller = controller;
    _opacity = new QGraphicsOpacityEffect();
    _opacity->setOpacity(0.5);
    setGraphicsEffect(_opacity);
    setAcceptHoverEvents(true);
}
QRectF MainSceneButton::boundingRect()const
{
    QRectF rect(-0.5*_width,-0.5*_height,_width,_height);
    return rect;
}
void MainSceneButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    painter->drawRect(boundingRect());
    painter->drawRect(QRect(-0.4*_width,-0.4*_height,0.8*_width,0.8*_height));
    painter->restore();
}
QString MainSceneButton::getCaption()const
{
    return _caption;
}
void MainSceneButton::setCaption(QString caption)const
{
    _caption = caption;
}
void MainSceneButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    _opacity->setOpacity(1);
}
void MainSceneButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    _opacity->setOpacity(0.5);
}
}
