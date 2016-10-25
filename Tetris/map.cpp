
//map.cpp
#include <QPainter>
#include <QBrush>
#include <QPixmap>
#include <QDebug>


#include "map.h"
#include "block.h"
namespace Teris
{
GameMap::GameMap():QGraphicsScene()
{
    setBackgroundBrush(Qt::black);
}
void GameMap::deleteLine(int y)
{

}

}
