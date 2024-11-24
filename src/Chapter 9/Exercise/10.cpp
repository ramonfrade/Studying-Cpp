#include "ppp2/std_lib_facilities.h"

bool leapyear(int y)
{
    if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
    {
        return true;
    }
    return false;
}