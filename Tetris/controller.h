#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTimer>
#include <QVector>
#include <QGraphicsScene>
namespace Teris
{
class Teris;
class Controller:public QObject
{
    Q_OBJECT
public:
    Controller(QGraphicsScene* scene,QObject* parent = 0);
protected:
   virtual void init();
private:
    Teris* _teris;
    QGraphicsScene* _scene;
    QTimer _timer;
};
}
#endif // CONTROLLER_H
