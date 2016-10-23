

#include "controller.h"
#include "teris.h"
#include "time.h"

namespace Teris
{
Controller::Controller(QGraphicsScene* scene, QObject *parent):
    QObject(parent),
    _scene(scene)
{

    init();
}

void Controller::init()
{
    _timer.start(1000/33);
    qsrand((unsigned)time(0));
    int itype = qrand() % 7;
    Teris::TerisType type;
    switch(itype)
    {
    case 0:
        type = Teris::L;
        break;
    case 1:
        type = Teris::RL;
        break;
    case 2:
        type = Teris::Z;
        break;
    case 3:
        type = Teris::RZ;
        break;
    case 4:
        type = Teris::O;
        break;
    case 5:
        type = Teris::I;
        break;
    case 6:
        type = Teris::T;
        break;
    default:
        break;
    }
    _teris = new Teris(mapWidth/2,0,type,100);

}
}
