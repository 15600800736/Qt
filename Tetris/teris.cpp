

//Teris_CPP
#include <QPainter>
#include <QTransform>
#include <QDebug>

#include "block.h"
#include "constants.h"
#include "map.h"
#include "teris.h"
#include "time.h"
namespace  Teris
{
Teris::Teris(qreal x, qreal y, int speed, GameMap* map, QObject* parent):
    QObject(parent),
    _startPos(x,y),
    _currentAngle(0),
    _speed(speed),
    _counter(0),
    _colorEffect(new QGraphicsColorizeEffect()),
    _map(map)
{
    for(int i = 0;i<4;i++)
    {
        Block* block = new Block();
        _block<<block;
        addToGroup(block);
    }
    setPos(x,y);
    reset();
    this->setGraphicsEffect(_colorEffect);
}
void Teris::create()
{
    switch(_type)
    {
    case L:
        _colorEffect->setColor(QColor(255,0,0));
        _block.at(0)->setPos(-0.5*blockWidth,-1.5*blockWidth);
        _block.at(1)->setPos(-0.5*blockWidth,-0.5*blockWidth);
        _block.at(2)->setPos(-0.5*blockWidth,0.5*blockWidth);
        _block.at(3)->setPos(0.5*blockWidth,0.5*blockWidth);
        break;
    case RL:
         _colorEffect->setColor(QColor(0,255,0));
         _block.at(0)->setPos(0.5*blockWidth,-1.5*blockWidth);
         _block.at(1)->setPos(0.5*blockWidth,-0.5*blockWidth);
         _block.at(2)->setPos(0.5*blockWidth,0.5*blockWidth);
         _block.at(3)->setPos(-0.5*blockWidth,0.5*blockWidth);
        break;
    case I:
        _colorEffect->setColor(QColor(0,0,255));
        _block.at(0)->setPos(-1.5*blockWidth,-0.5*blockWidth);
        _block.at(1)->setPos(-0.5*blockWidth,-0.5*blockWidth);
        _block.at(2)->setPos(0.5*blockWidth,-0.5*blockWidth);
        _block.at(3)->setPos(1.5*blockWidth,-0.5*blockWidth);
        break;
    case T:
        _colorEffect->setColor(QColor(255,85,0));
        _block.at(0)->setPos(-0.5*blockWidth,-0.5*blockWidth);
        _block.at(1)->setPos(-1.5*blockWidth,0.5*blockWidth);
        _block.at(2)->setPos(-0.5*blockWidth,0.5*blockWidth);
        _block.at(3)->setPos(0.5*blockWidth,0.5*blockWidth);
        break;
    case Z:
        _colorEffect->setColor(QColor(255,0,127));
        _block.at(0)->setPos(-1.5*blockWidth,-0.5*blockWidth);
        _block.at(1)->setPos(-0.5*blockWidth,-0.5*blockWidth);
        _block.at(2)->setPos(-0.5*blockWidth,0.5*blockWidth);
        _block.at(3)->setPos(0.5*blockWidth,0.5*blockWidth);
        break;
    case RZ:
        _colorEffect->setColor(QColor(170,85,255));
        _block.at(0)->setPos(1.5*blockWidth,-0.5*blockWidth);
        _block.at(1)->setPos(0.5*blockWidth,-0.5*blockWidth);
        _block.at(2)->setPos(0.5*blockWidth,0.5*blockWidth);
        _block.at(3)->setPos(-0.5*blockWidth,0.5*blockWidth);
        break;
    case O:
        _colorEffect->setColor(QColor(255,255,0));
        _block.at(0)->setPos(-0.5*blockWidth,-0.5*blockWidth);
        _block.at(1)->setPos(-0.5*blockWidth,0.5*blockWidth);
        _block.at(2)->setPos(0.5*blockWidth,-0.5*blockWidth);
        _block.at(3)->setPos(0.5*blockWidth,0.5*blockWidth);
        break;
    default:
        break;
    }
}
QRectF Teris::boundingRect()const
{
    QRectF rect(-2*blockWidth,2*blockWidth,
                  4*blockWidth,4*blockWidth);
     return rect;
}
QPainterPath Teris::shape()const
{
    QPainterPath path;
    Block*block;
    foreach(block,_block)
    {
        QPointF topLeft(block->x()-0.5*blockWidth,block->y() - 0.5*blockWidth);
        QPointF bottomRight(block->x()+0.5*blockWidth,block->y() + 0.5*blockWidth);
        path.addRect(QRectF(topLeft,bottomRight));
    }
    return path;

}
void Teris::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}
bool Teris::isColliding()
{
    QList<QGraphicsItem*> child = childItems();
    foreach(QGraphicsItem* one,child)
    {
        QList<QGraphicsItem*> colliding = one->collidingItems();
        if(colliding.size() > 0 && !(colliding.size() == 1 && colliding.at(0) == this))
        {
            return true;
        }
    }
    return false;
}

void Teris::fall()
{
    QPointF oldPos= this->pos();
    moveBy(0,blockWidth/5);
    if(isColliding())
    {
        setPos(oldPos);
        _action = STOP;
        update(_map->sceneRect());
        return;
    }
}
void Teris::move()
{
    switch(_action)
    {
    case LEFT:
    {
        moveBy(-blockWidth,0);
        if(isColliding())
        {
            moveBy(blockWidth,0);
        }
        break;
    }
    case RIGHT:
    {
        moveBy(blockWidth,0);
        if(isColliding())
        {
            moveBy(-blockWidth,0);
        }
        break;
    }
    case DOWN:
    {
        _counter = _speed;
        break;
    }
    case TURN:
    {
        _currentAngle += 90;
        if(_currentAngle == 360)
        {
            _currentAngle = 0;
        }
        setRotation(_currentAngle);
        if(isColliding())
        {
                _currentAngle -= 90;
                 setRotation(_currentAngle);
        }
        break;
    }
    default:
        break;
    }
}
void Teris::advance(int phase)
{
    if(!phase)return;
    if(++_counter < _speed)return;
    _counter = 0;
    move();
    fall();
    if(_action != STOP)
    {
         _action = FALL;
    }
    else
    {
        QPair<qreal,qreal> minMax = sendBlockToMap();
        reset();
        _map->deleteLine(minMax);
    }
}
QPair<qreal, qreal> Teris::sendBlockToMap()
{
    QPair<qreal,qreal> minMax;
    minMax.first = _block.at(0)->scenePos().y();
    minMax.first = _block.at(0)->scenePos().y();
    foreach(Block* block,_block)
    {
        minMax.first = block->scenePos().y()< minMax.first ? block->scenePos().y() : minMax.first;
        minMax.second = block->scenePos().y() > minMax.second ? block->scenePos().y() : minMax.second;
        Block *oldBlock = new Block(block->scenePos());
        _map->addItem(oldBlock);
    }
    return minMax;
}
void Teris::reset()
{
    setPos(_startPos);
    setRotation(0);
    qsrand((unsigned int)time(0));
    _action = FALL;
    int type = qrand() % 7;
    switch(type)
    {
    case 0:
        _type = I;
        break;
    case 1:
        _type = L;
        break;
    case 2:
        _type =RL;
        break;
    case 3:
        _type = Z;
        break;
    case 4:
        _type = RZ;
        break;
    case 5:
        _type = T;
        break;
    case 6:
        _type = O;
        break;
    default:
        break;
    }
    create();
    if(isColliding())
    {
        emit gameOver();
    }
}
void Teris::setType(TerisType type)
{
    _type = type;
}
Teris::~Teris()
{
    _block.clear();
    delete _colorEffect;
}
void Teris::setAction(Action action)
{
    _action = action;
}
}

