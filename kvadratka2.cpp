/*
   \brief  Программа рещающая квадратные уравнения

   \param[out] x1     Первый корень квадратного уравнения
   \param[out] x2     Второй корень квадратного уравнения
   \param[in] a       Первый коэффицент квадратного уравнения
   \param[in] b       Второй коэффицент квадратного уравнения
   \param[in] c       Свободный член квадратного уравнения
   \param[in] n_root  Количество решений квадратного уравнения
   \param[in] n       Число, которое контролирует, чтоб при вводе a, b, c выводилась --- ERROR
   \param[in] a1      Первый коэффицент квадратного уравнения в функции TEST_SS()
   \param[in] b1      Второй коэффицент квадратного уравнения в функции TEST_SS()
   \param[in] c1      Свободный член квадратного уравнения в функции TEST_SS()
   \param[in] i       Общий счетчик количества проверок
   \param[in] j       Счетчик для проверки случая, когда количество решений бесконечно
   \param[in]
   \param[in]
   \param[in]




 */

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#define EPS 0.000001                           //Некоторая константа показывающая наибольшую разность между 0 и числом(чтоб избежать погрешности)
#define INF_ROOT 3

int Check0(double num);

int SolveSquare(double a,double b,double c, double* x1, double* x2);

void TEST_SS();

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


/*void TEST_SS()
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
} */

void TEST_SS()                                            //проверяет корни уравнения при рандомных коэффицентах
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
            if (!(Check0((a1*x1*x1 + b1*x1 + c1)) && Check0((a1*x2*x2 + b1*x2 + c1))))          //проверка если уранение имеет 2 корня
            {
                printf("FALED: a1 = %d, b1 = %d, c1 = %d, x1 = %lg, x2 = %lg, SS1 - %lg, SS2 - %lg\n", a1, b1, c1, x1, x2, a1*x1*x1 + b1*x1 + c1, a1*x2*x2 + b1*x2 + c1);
            }
            //assert((a1*x1*x1 + b1*x1 + c1) == 0 && (a1*x2*x2 + b1*x2 + c1) == 0);

        if (n_root == 1)                                                                       //проверка если уравнение имеет 1 корень
            if (!(Check0((a1*x1*x1 + b1*x1 + c1))))
            {
                printf("FALED: a1 = %d, b1 = %d, c1 = %d, x1 = %lg, SS1 - %lg\n", a1, b1, c1, x1, a1*x1*x1 + b1*x1 + c1);
            }

            //assert(Check0((a1*x1*x1 + b1*x1 + c1)));

        if (n_root == INF_ROOT)                                                                //проверка если уравнение имеет бесконечно корней
        {
            int x_1 = 0;
            int j = 0;

            while (j++ < 3)        //3 проверки, поскольку если квадратное уравнение если имеет больше 2 корней, значит их бесконечно
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

int Check0(double num)                                    //проверяет близкие к 0 значения для операций * == 0 и * != 0 для чисел с плавающей точкой
{
    if (num < EPS && num > -EPS)
        return 1;
    else
        return 0;
}
