
//map.cpp
#include <QPainter>
#include <QBrush>
#include <QPixmap>
#include <QDebug>
#include <QGraphicsItemGroup>
#include <QGraphicsOpacityEffect>
#include <QPixmap>

#include "map.h"
#include "teris.h"
namespace Teris
{
GameMap::GameMap():QGraphicsScene(),_nextTeris(new Teris(mapWidth,-0.2*mapLength,0,this))
{
    _nextTeris->setAction(Teris::NEXT);
    init();
    setSceneRect(-mapWidth,-mapLength,6*mapWidth,6*3/4*mapWidth);
    addItem(_nextTeris);
}
void GameMap::init()
{
    QPen linePen(Qt::white,1,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
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
void GameMap::createNextTeris(int type)
{
    Teris::TerisType nextType;
    switch(type)
    {
    case 0:
        nextType = Teris::I;
        break;
    case 1:
        nextType = Teris::L;
        break;
    case 2:
        nextType = Teris::RL;
        break;
    case 3:
        nextType = Teris::Z;
        break;
    case 4:
        nextType = Teris::RZ;
        break;
    case 5:
        nextType = Teris::T;
        break;
    case 6:
        nextType = Teris::O;
        break;
    default:
        break;
    }
    _nextTeris->setType(nextType);
    _nextTeris->create();
}
void GameMap::drawBackground(QPainter *painter, const QRectF &rect)
{
    painter->save();
    painter->drawPixmap(-mapWidth,-mapLength,6*mapWidth,6*3/4*mapWidth,QPixmap(":images/background"));
    painter->restore();
    painter->save();
    painter->setPen(QPen(Qt::blue,10));
    painter->drawRoundRect(-0.5*mapWidth-10,-0.5*mapLength-10,mapWidth+20,mapLength+20,10,10);
    painter->setPen(QPen(Qt::white,5));
    painter->drawRoundRect(-0.5*mapWidth-4,-0.5*mapLength-4,mapWidth+8,mapLength+8,10,10);
    painter->restore();
}
}
