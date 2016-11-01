
#include "mainscene.h"
#include "constants.h"

namespace Teris
{
MainScene::MainScene(Controller* controller)
{
    setSceneRect(-30*blockWidth,-20*blockWidth,60*blockWidth,40*blockWidth);
    _startButton = new StartButton(120,40,0,0,controller);
    addItem(_startButton);
}
}
