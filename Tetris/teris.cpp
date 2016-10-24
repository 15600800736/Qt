

//Teris_CPP
#include <QPainter>
#include <QTransform>
#include "teris.h"
#include "constants.h"
#include "block.h"
#include "map.h"
namespace  Teris
{
Teris::Teris(qreal x, qreal y, TerisType type, int speed, GameMap* map):
    _type(type),
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
    create();
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
        path.addPath(block->shape());
    }
    return path;
}
void Teris::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shape(),Qt::red);
    painter->restore();
}
void Teris::move()
{
    switch(_action)
    {
    case LEFT:
    {
        moveBy(-blockWidth,0);
        break;
    }
    case RIGHT:
    {
        moveBy(blockWidth,0);
        break;
    }
    case DOWN:
    {
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
    if(_action != STOP)
    {
        move();
        handleCollision();
    }
}
void Teris::handleCollision()
{
    QList<QGraphicsItem*> collisionItems = collidingItems();
}
Teris::~Teris()
{
    foreach(Block* block,_block)
    {
        delete block;
    }
    delete _colorEffect;
}
void Teris::sendTerisToMap()
{
    foreach(Block* block,_block)
    {
        QPointF posInScene = block->mapToScene(block->pos());
        _map->receiveBlock(posInScene);
    }
}

}

