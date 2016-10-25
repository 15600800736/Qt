#ifndef MAP_H
#define MAP_H

#include <QVector>
#include <QSet>
#include <QRectF>
#include <QPainterPath>
#include <QGraphicsScene>

#include "constants.h"
namespace Teris
{
class Block;
class GameMap:public QGraphicsScene
{
public:
    GameMap();
    void receiveBlock(Block block);
    void deleteLine(int y);
};
}
#endif // MAP_H
