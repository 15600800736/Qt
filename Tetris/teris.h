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
class GameMap;
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
    Teris(qreal x,qreal y,TerisType type,int speed,GameMap* map);
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
    void sendTerisToMap();

private:
    int _speed;
    int _counter;
    TerisType _type;
    QGraphicsColorizeEffect* _colorEffect;
    QList<Block*> _block;
    angle _currentAngle;
    Action _action;
    GameMap* _map;
//    Controller* _controller;
};
}
#endif // Teris_H
