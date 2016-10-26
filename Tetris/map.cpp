
//map.cpp
#include <QPainter>
#include <QBrush>
#include <QPixmap>
#include <QDebug>
#include <QGraphicsItemGroup>
#include <QGraphicsOpacityEffect>

#include "map.h"
#include "block.h"
namespace Teris
{
GameMap::GameMap():QGraphicsScene()
{
    init();
    setSceneRect(-mapWidth,-mapLength,4*mapWidth,2*mapLength);
}
void GameMap::init()
{
    QPen linePen(Qt::red,1,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    for(int i = 0;i<4;i++)
    {
        _boundary.push_back(new QGraphicsLineItem());
        _boundary.back()->setPen(linePen);
        addItem(_boundary.back());
    }
    _boundary.at(0)->setLine(-0.5*mapWidth-1,-0.5*mapLength-1,0.5*mapWidth+1,-0.5*mapLength-1);
    _boundary.at(1)->setLine(-0.5*mapWidth-1,0.5*mapLength+1,0.5*mapWidth+1,0.5*mapLength+1);
    _boundary.at(2)->setLine(-0.5*mapWidth-1,-0.5*mapLength-1,-0.5*mapWidth-1,0.5*mapLength+1);
    _boundary.at(3)->setLine(0.5*mapWidth+1,-0.5*mapLength-1,0.5*mapWidth+1,0.5*mapLength-1);
    setBackgroundBrush(Qt::black);
}
void GameMap::clearBlock(QList<QGraphicsItem *> block)
{
    QRect rect(-0.5*mapWidth,-0.5*mapLength,mapWidth,block.at(0)->y()-blockWidth+0.5*mapLength);
    foreach(QGraphicsItem* one,block)
    {
        removeItem(one);
        delete one;
        update(sceneRect());
    }
    QList<QGraphicsItem*> itemsDown = items(rect);
    foreach(QGraphicsItem* item,itemsDown)
    {
        item->moveBy(0,blockWidth);
    }
}

void GameMap::deleteLine(QPair<qreal, qreal> minMax)
{
    for(minMax.first;minMax.first < minMax.second + 1; minMax.first += blockWidth)
    {
        QRectF rect(-0.5*mapWidth,minMax.first-0.5*blockWidth,mapWidth,blockWidth);
        QList<QGraphicsItem*> oneLineBlock = items(rect);
        if(oneLineBlock.size() == (mapWidth/blockWidth)-1)
        {
            clearBlock(oneLineBlock);
        }
    }
}
void GameMap::removeAll()
{
    QRectF map(-0.5*mapWidth,-0.5*mapLength,mapWidth,mapLength);
    QList<QGraphicsItem*> allBlocks = items(map);
    foreach(QGraphicsItem* one,allBlocks)
    {
        removeItem(one);
        delete one;
    }
}
}
