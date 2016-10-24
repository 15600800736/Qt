#ifndef MAP_H
#define MAP_H

#include "constants.h"
#include <QGraphicsItemGroup>
#include <QVector>
#include <QSet>
#include <QRectF>
#include <QPainterPath>
namespace Teris
{
class Block;
class GameMap:public QGraphicsItemGroup
{
public:
    GameMap();
    void receiveBlock(QPointF blockPosInScene);
    void deleteLine(int y);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QVector<QSet<Block*>* > _matrix;
};
}
#endif // MAP_H
