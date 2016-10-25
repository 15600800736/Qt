#ifndef TESTTERIS_H
#define TESTTERIS_H

#include "teris.h"
namespace Teris
{
class Test:public Teris
{
public:
    void advance(int phase);
};
}
#endif // TESTTERIS_H
