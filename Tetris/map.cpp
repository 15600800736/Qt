
//map.cpp
#include <QPainter>
#include <QBrush>
#include <QPixmap>

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
    addToGroup(block);
    if(_matrix[y]->size() == mapWidth)
    {
//        deleteLine(y);
    }
    update(boundingRect());
}
QPainterPath GameMap::shape()const
{
    QPainterPath path;
    foreach(QSet<Block*>* set,_matrix)
    {
        foreach(Block* block,*set)
        {
            path.addPath(block->shape());
        }
    }
    return path;
}
QSet<Block*>* GameMap::resetSet(int y)
{
    QSet<Block*>* theSet = _matrix[y];
    foreach(Block* deleteBlock,*theSet)
    {
        delete deleteBlock;
    }
    theSet->clear();
    return theSet;
}

void GameMap::deleteLine(int y)
{
    QSet<Block*>* theSet = resetSet(y);
    for(int i = y;i>0;i++)
    {
        _matrix[y] = _matrix[y-1];
    }
    _matrix[0] = theSet;
    update(boundingRect());
}

void GameMap::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    painter->drawPixmap(-0.5*mapWidth,-0.5*mapLength,mapWidth,mapLength,QPixmap(":images/gameBackground"));
    painter->setBrush(Qt::red);
    painter->drawEllipse(0,0,10,10);
    painter->restore();
    painter->save();
    painter->fillPath(shape(),QBrush());
    painter->restore();
}


}
