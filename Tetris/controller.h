#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTimer>
#include <QVector>
#include <QGraphicsScene>
#include <QGraphicsView>
namespace Teris
{
class Teris;
class GameMap;
class Controller:public QObject
{
    Q_OBJECT
public:
    Controller(QObject* parent = 0);
    virtual ~Controller();
    virtual void startGame();
    bool eventFilter(QObject *watched, QEvent *event);
private:
    GameMap* _map;
    Teris* _teris;
    QGraphicsView* _view;
    QTimer _timer;
};
}
#endif // CONTROLLER_H
