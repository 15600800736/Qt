#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGraphicsScene>

namespace Teris
{
class MainScene:public QObject,public QGraphicsScene
{
    Q_OBJECT
public:
    MainScene(QObject* parent = 0);
    void drawBackground(QPainter *painter, const QRectF &rect);
};
}
#endif // MAINSCENE_H
