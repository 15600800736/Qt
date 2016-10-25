#ifndef CONSTANCE_H
#define CONSTANCE_H
#include <QObject>

#define yToIndex(y) ((0.5*mapLength - 0.5*blockWidth - y)/blockWidth)
const int blockWidth = 20;
const int mapWidth = 15*blockWidth;
const int mapLength = 30*blockWidth;
const qreal barLength = blockWidth;
const qreal barWidth = 5;
#endif // CONSTANCE_H
