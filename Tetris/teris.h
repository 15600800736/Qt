#ifndef Teris_H
#define Teris_H

#include <QGraphicsItemGroup>
#include <QList>
#include <QGraphicsColorizeEffect>

#include "constants.h"
namespace Teris
{
class Controller;
class Block;
class GameMap;
class Teris : public QGraphicsItemGroup
{
public:

    typedef enum
    {
        FALL,
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

    Teris(qreal x,qreal y,int speed,GameMap* map);
    QRectF boundingRect()const;
    QPainterPath shape()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void reset();
    void setType(TerisType type);
    void setAction(Action action);

    ~Teris();
protected:
    bool move();
    bool Fall();
    void create();
    void advance(int phase);
    void sendBlockToMap();
private:
    int _speed;
    int _counter;
    TerisType _type;
    QGraphicsColorizeEffect* _colorEffect;
    QList<Block*> _block;
    QPointF _startPos;
    angle _currentAngle;
    Action _action;
    GameMap* _map;
//    Controller* _controller;
};
}
#endif // Teris_H
