#ifndef BOUNDARY_H
#define BOUNDARY_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPainterPath>
#include <QColor>

#include "constants.h"
namespace Teris
{
class Bar:public QGraphicsItem
{
public:
    Bar(QColor color);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect()const;
    QPainterPath shape()const;
private:
    QColor _color;
};
}
#endif // BOUNDARY_H
