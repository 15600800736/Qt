#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGraphicsScene>

#include "startbutton.h"

namespace Teris
{
class Controller;
class MainScene:public QGraphicsScene
{
public:
    MainScene(Controller* controller);
private:
    MainSceneButton* _startButton;

};
}
#endif // MAINSCENE_H
