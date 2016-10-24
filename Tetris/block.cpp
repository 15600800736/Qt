
//block.cpp

#include "block.h"
#include "constants.h"
#include <QPainter>
#include <QPixmap>
namespace Teris
{
Block::Block()
{

}
Block::Block(QPointF& pos)
{
    setPos(pos);
}
Block::Block(qreal x, qreal y)
{
    setPos(x,y);
}
Block::Block(const Block &other)
{
    other.setPos(pos());
}

QRectF Block::boundingRect()const
{
    QRectF rect(-blockWidth/2,-blockWidth/2,blockWidth,blockWidth);
    return rect;
}
QPainterPath Block::shape()const
{
    QPainterPath path;
    path.addRect(-blockWidth/2,-blockWidth/2,blockWidth,blockWidth);
    return path;

}
void Block::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    painter->drawPixmap(-blockWidth/2,-blockWidth/2,blockWidth,blockWidth,QPixmap(":images/block"));
    painter->restore();
}
}
