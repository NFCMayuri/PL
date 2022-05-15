#include <stdio.h>
#include "../include/resistorcal.h"
double resistorcal(double R1, double R2, char type)
{
    switch (type)
    {
    case '1':
        return (R1 * R2) / (R1 + R2);
        break;
    case '2':
        return (R1 * R2) / (R1 - R2);
        break;
    }
}
