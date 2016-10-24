

//map.cpp


#include "map.h"
#include "block.h"
namespace Teris
{
GameMap::GameMap()
{
    for(int i = 0; i < mapLength; i++)
    {
        _matrix.push_back(new QSet<Block*>());
    }

}
QRectF GameMap::boundingRect()const
{
    QRectF rect(-0.5*mapWidth,-0.5*mapLength,mapWidth,mapLength);
    return rect;
}

void GameMap::receiveBlock(QPointF blockPosInScene)
{
    QPointF blockPos = mapFromScene(blockPosInScene);
    Block* block = new Block(blockPos);
    int y = block->y();
    _matrix[y]->insert(block);
    if(_matrix[y]->size() == mapWidth)
    {
        deleteLine(y);
    }
    update(boundingRect());
}
}
