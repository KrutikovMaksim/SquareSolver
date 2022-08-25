#pragma once

#define EPS 0.000001

int Check0(double num)                                    //проверяет близкие к 0 значения для операций * == 0 и * != 0 для чисел с плавающей точкой
{
    if (num < EPS && num > -EPS)
        return 1;
    else
        return 0;
}
