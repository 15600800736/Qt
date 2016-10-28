#ifndef BUTTON_H
#define BUTTON_H

#include "QPushButton"
#include "QGraphicsItem"

namespace Teris
{
class AbstractButton:public QGraphicsItem
{
public:
    Button(qreal x,qreal y,qreal width,qreal height);
    virtual qreal size()const = 0;
    virtual QString caption() = 0;
    virtual int identify()const = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;
    virtual void mousePressEvent() = 0;
    virtual void mouseReleaseEvent() = 0;
    virtual QRectF boundingRect()const = 0;
};
}
#endif // BUTTON_H
