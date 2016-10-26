#ifndef BOUNDARY_H
#define BOUNDARY_H

#include <QGraphicsItem>

namespace Teris
{
class Boundary:public QGraphicsItem
{
public:
    Boundary();
    Boundary(qreal x, qreal y, qreal width, qreal length);
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setWidth(qreal width);
    void setLength(qreal length);
private:
    qreal _width;
    qreal _length;
};
}
#endif // BOUNDARY_H
