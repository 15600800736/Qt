#ifndef MAINSCENEBUTTON_H
#define MAINSCENEBUTTON_H

#include <QGraphicsItem>
#include <QGraphicsOpacityEffect>
#include <QGraphicsDropShadowEffect>

namespace Teris
{
class Controller;
class MainSceneButton:public QGraphicsItem
{
public:
    MainSceneButton(QString caption,qreal width,qreal height,qreal x,qreal y,Controller* controller);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) = 0;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) = 0;
    QRectF boundingRect()const;
    QString getCaption()const;
    void setCaption(QString caption);
protected:
    qreal _width;
    qreal _height;
    QString _caption;
    QGraphicsDropShadowEffect* _shadow;
    QGraphicsOpacityEffect* _opacity;
    Controller* _controller;
};
}
#endif // MAINSCENEBUTTON_H
