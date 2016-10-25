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
    bool fall();
    void create();
    void advance(int phase);
    void sendBlockToMap();
    bool isColliding();
private:

    TerisType _type;

    QList<Block*> _block;
    QPointF _startPos;
    angle _currentAngle;
    int _speed;
    int _counter;
    Action _action;
    QGraphicsColorizeEffect* _colorEffect;
    GameMap* _map;
};
}
#endif // Teris_H
