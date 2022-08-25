#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "SolveSquare.h"
#include "TEST_SS.h"

#define EPS 0.000001                           //Некоторая константа показывающая наибольшую разность между 0 и числом(чтоб избежать погрешности)
#define INF_ROOT 3

int main(void)
{
    int n = 0;

    double a = 0, b = 0, c = 0;
    printf("# Enter a b c: ");

    if (scanf("%lg %lg %lg", &a, &b, &c) == 3)   //проверяет чтоб было введено 3 числа
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

