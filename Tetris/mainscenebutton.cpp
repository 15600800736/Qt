
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
    _shadow = new QGraphicsDropShadowEffect();
    _shadow->setBlurRadius(0);
    _shadow->setOffset(0,0);
    _opacity = new QGraphicsOpacityEffect();
    _opacity->setOpacity(0.2);
    setGraphicsEffect(_shadow);
    setAcceptHoverEvents(true);
}
QRectF MainSceneButton::boundingRect()const
{
    QRectF rect(-0.5*_width,-0.5*_height,_width,_height);
    return rect;
}
QString MainSceneButton::getCaption()const
{
    return _caption;
}
void MainSceneButton::setCaption(QString caption)
{
    _caption = caption;
}
void MainSceneButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    _shadow->setBlurRadius(10);
    _shadow->setOffset(7,4);
    setPos(x()-3,y()-3);
}
void MainSceneButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
     setPos(x()+3,y()+3);
    _shadow->setBlurRadius(0);
    _shadow->setOffset(0,0);

}
}
