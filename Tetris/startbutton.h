#ifndef STARTBUTTON_H
#define STARTBUTTON_H

#include "abstractbutton.h"

namespace Teris
{
class StartButton:public AbstractButton
{
public:
    StartButton(qreal x,qreal y,qreal width,qreal height,QString caption);
    qreal size()const;
    QString caption();
    int identify()const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void mousePressEvent();
    virtual void mouseReleaseEvent();
    virtual QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QString _caption;
};
}
#endif // STARTBUTTON_H
