#ifndef Teris_H
#define Teris_H


#include <QGraphicsItemGroup>
#include <QList>
#include "constants.h"
#include <QGraphicsColorizeEffect>
#include <QTransform>
namespace Teris
{
class Controller;
class Block;

class Teris : public QGraphicsItemGroup
{
public:

    typedef enum
    {
        LEFT,
        RIGHT,
        DOWN,
        STOP,
        TURN
    } Action;
    typedef enum
    {
        I,
        L,
        RL,
        Z,
        RZ,
        T,
        O,
    }TerisType;
    typedef int angle;
    Teris(qreal x,qreal y,TerisType type,int speed);
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape()const;
    ~Teris();
protected:
    void move();
    void create();
    void advance(int phase);
    void handleCollision();
    void handleDeleteLine();
    QPointF getPos()const;
private:
    int _speed;
    int _counter;
    QPointF _pos;
    TerisType _type;
    QGraphicsColorizeEffect* _colorEffect;
    QList<Block*> _block;
    angle _currentAngle;
    Action _action;
//    Controller* _controller;
};
}
#endif // Teris_H
