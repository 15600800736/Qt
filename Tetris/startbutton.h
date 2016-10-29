#ifndef STARTBUTTON_H
#define STARTBUTTON_H

#include "mainscenebutton.h"

namespace Teris
{
class StartButton:public MainSceneButton
{
   StartButton(qreal width, qreal height, qreal x, qreal y, Controller* controller);
   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
   void mousePressEvent(QGraphicsSceneMouseEvent* event);
   void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
};
}
#endif // STARTBUTTON_H
