#ifndef BLOCK_H
#define BLOCK_H
#include <QGraphicsItem>
#include <QRectF>
#include <QPainterPath>
#include <QColor>
namespace Teris
{

class Block:public QGraphicsItem
{
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape()const;
    QRectF boundingRect()const;
};
}
#endif // BLOCK_H
