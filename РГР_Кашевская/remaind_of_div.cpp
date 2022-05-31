#include "remaind_of_div.h"

int remaind_of_div(int a, int x, int p)
{
    int remaind = 1;
    for (int i = 1; i <= x; i++)
    {
        remaind *= a;
        remaind %= p;
    }
    return remaind;
}
