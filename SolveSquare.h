#include "Check0.h"

#define INF_ROOT 3

int SolveSquare(double a,double b,double c, double* x1, double* x2)
{
    if (Check0(a))
    {
        if (Check0(b))
        {
            if (Check0(c))
            {
                return INF_ROOT;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            *x1 = -c / b;
            return 1;
        }
    }
    else
    {
        if (Check0(b))
        {
            if (Check0(c))
            {
                *x1 = 0;
                return 1;
            }
            else if((-c / a) < 0)
            {
                return 0;
            }
            else
            {
                *x1 = -sqrt(-c / a);
                *x2 = sqrt(-c / a);
                return 2;
            }
        }
        else
        {
            if (Check0(c))
            {
                *x1 = 0;
                *x2 = -b / a;
                return 2;
            }
            else
            {
                if ((b*b - 4*a*c) < 0)
                {
                    return 0;
                }
                else if (Check0((b*b - 4*a*c)))
                {
                    *x1 = -b / (2*a);
                    return 1;
                }
                else
                {
                    *x1 = (-b - sqrt(b*b - 4*a*c)) / (2 * a);
                    *x2 = (-b + sqrt(b*b - 4*a*c)) / (2 * a);
                    return 2;
                }
            }
        }
    }
}

