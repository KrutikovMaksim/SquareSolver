#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#define EPS 0.000001                           
#define INF_ROOT 3

int Check0(double num);

int SolveSquare(double a,double b,double c, double* x1, double* x2);

void TEST_SS1();
void TEST_SS();

int main(void)
{
    int n = 0;

    double a = 0, b = 0, c = 0;
    printf("# Enter a b c: ");

    if (scanf("%lg %lg %lg", &a, &b, &c) == 3)   
        n = 3;

    double x1 = 0, x2 = 0;

    int n_root = SolveSquare(a, b, c, &x1, &x2);

    if (n < 3)
        n_root = 456;

    switch (n_root) {
    case 0:
        printf("No roots\n");
        break;
    case 1:
        printf("x = %lg\n", x1);
        break;
    case 2:
        printf("x1 = %lg, x2 = %lg\n", x1, x2);
        break;
    case INF_ROOT:
        printf("Any roots\n");
        break;
    default:
        printf("ERROR\n");
    }

    TEST_SS();

    return 0;
}

/*
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


void TEST_SS1()
{
    double x1 = 0, x2 = 0;
    int n_root = SolveSquare(0, 0, 0, &x1, &x2);
    assert (n_root == INF_ROOT && x1 == 0 && x2 == 0);

    x1 = 0, x2 = 0;
    n_root = SolveSquare(0, 0, 1, &x1, &x2);
    assert (n_root == 0 && x1 == 0 && x2 == 0);

    x1 = 0, x2 = 0;
    n_root = SolveSquare(0, 1, 0, &x1, &x2);
    assert (n_root == 1 && x1 == 0 && x2 == 0);

    x1 = 0, x2 = 0;
    n_root = SolveSquare(0, 1, 1, &x1, &x2);
    assert (n_root == 1 && x1 == -1 && x2 == 0);

    x1 = 0, x2 = 0;
    n_root = SolveSquare(1, 0, 0, &x1, &x2);
    assert (n_root == 1 && x1 == 0 && x2 == 0);

    x1 = 0, x2 = 0;
    n_root = SolveSquare(1, 0, 1, &x1, &x2);
    assert (n_root == 0 && x1 == 0 && x2 == 0);

    x1 = 0, x2 = 0;
    n_root = SolveSquare(1, 0, -1, &x1, &x2); //
    assert (n_root == 2 && x1 == -1 && x2 == 1);

    x1 = 0, x2 = 0;
    n_root = SolveSquare(1, 1, 0, &x1, &x2);
    assert (n_root == 2 && x1 == 0 && x2 == -1);

    x1 = 0, x2 = 0;
    n_root = SolveSquare(1, 2, 4, &x1, &x2);
    assert (n_root == 0 && x1 == 0 && x2 == 0);

    x1 = 0, x2 = 0;
    n_root = SolveSquare(1, -2, 1, &x1, &x2);
    assert (n_root == 1 && x1 == 1 && x2 == 0);

    x1 = 0, x2 = 0;
    n_root = SolveSquare(1, -5, 6, &x1, &x2);
    assert (n_root == 2 && x1 == 2 && x2 == 3);
} 

void TEST_SS()                                            
{
    double x1 = 0, x2 = 0;
    int i = 0;

    int a1 = 0, b1 = 0, c1 = 0;

    while(i++ < 1000000)
    {
        a1 = rand() % 20001 +  -10000;
        b1 = rand() % 20001 +  -10000;
        c1 = rand() % 20001 +  -10000;

        int n_root = SolveSquare(a1, b1, c1, &x1, &x2);

        if (n_root == 2)
            if (!(Check0((a1*x1*x1 + b1*x1 + c1)) && Check0((a1*x2*x2 + b1*x2 + c1))))          
            {
                printf("FALED: a1 = %d, b1 = %d, c1 = %d, x1 = %lg, x2 = %lg, SS1 - %lg, SS2 - %lg\n", a1, b1, c1, x1, x2, a1*x1*x1 + b1*x1 + c1, a1*x2*x2 + b1*x2 + c1);
            }
            //assert((a1*x1*x1 + b1*x1 + c1) == 0 && (a1*x2*x2 + b1*x2 + c1) == 0);

        if (n_root == 1)                                                                       
            if (!(Check0((a1*x1*x1 + b1*x1 + c1))))
            {
                printf("FALED: a1 = %d, b1 = %d, c1 = %d, x1 = %lg, SS1 - %lg\n", a1, b1, c1, x1, a1*x1*x1 + b1*x1 + c1);
            }

            //assert(Check0((a1*x1*x1 + b1*x1 + c1)));

        if (n_root == INF_ROOT)                                                                
        {
            int x_1 = 0;
            int j = 0;

            while (j++ < 3)        
            {
                x_1 = rand() % 51 + -25;
                if (!(Check0((a1*x_1*x_1 + b1*x_1 + c1))))
                {
                    printf("FALED: a1 = %d, b1 = %d, c1 = %d, x_1 = %d, SS1 - %d\n", a1, b1, c1, x_1, a1*x_1*x_1 + b1*x_1 + c1);
                }

                //assert(Check0((a1*x_1*x_1 + b1*x_1 + c1)));
            }
        }

    }

}

int Check0(double num)                                    
{
    if (num < EPS && num > -EPS)
        return 1;
    else
        return 0;
}
*/
