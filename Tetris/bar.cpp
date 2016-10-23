
#include "bar.h"
#include <QPainter>
#include <QBrush>
namespace Teris
{
Bar::Bar(QColor color):_color(color)
{

}
QRectF Bar::boundingRect()const
{
    QRectF rect(-barWidth/2,barLength/2,barWidth,barLength);
    return rect;
}
QPainterPath Bar::shape()const
{
    QPainterPath path;
    path.addRect(-barWidth/2,barLength/2,barWidth,barLength);
    return path;
}
void Bar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    QBrush brush(QColor(170,0,0));
    painter->fillPath(shape(),brush);
    painter->restore();

    painter->save();
    qreal halfWidth = barWidth/2;
    qreal quarterWidth = halfWidth/2;
    qreal tenpLength = barLength/10;
    qreal eightpLength = barLength/8;
    qreal top = barLength/2 + tenpLength;
    for(int i = 0;i<4;i++)
    {
        QRectF rectf(-quarterWidth,top,halfWidth,eightpLength);
        painter->fillRect(rectf,_color);
        top += (tenpLength + eightpLength);
    }
}
}
