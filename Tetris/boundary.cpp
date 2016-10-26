
//boundary.cpp
#include "boundary.h"
#include <QPainter>

namespace Teris
{
Boundary::Boundary():_width(0),_length(0)
{
    setPos(0,0);
}

Boundary::Boundary(qreal x, qreal y, qreal width, qreal length):_width(width),_length(length)
{
    setPos(x,y);
}
QRectF Boundary::boundingRect()const
{
    QRectF rect(-0.5*_width,-0.5*_length,_width,_length);
    return rect;
}
void Boundary::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    painter->setBrush(Qt::red);
    painter->drawRoundedRect(boundingRect(),12,12);
    painter->restore();
}
void Boundary::setWidth(qreal width)
{
    _width = width;
}
void Boundary::setLength(qreal length)
{
    _length = length;
}
}
