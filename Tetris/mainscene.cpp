
#include "mainscene.h"
#include "constants.h"

namespace Teris
{
MainScene::MainScene(Controller* controller)
{
    setSceneRect(-10*blockWidth,-10*blockWidth,20*blockWidth,20*blockWidth);
    _startButton = new StartButton(120,40,0,0,controller);
    addItem(_startButton);
}
}
