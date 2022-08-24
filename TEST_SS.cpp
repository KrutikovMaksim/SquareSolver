void TEST_SS()                                            //��������� ����� ��������� ��� ��������� ������������
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
            if (!(Check0((a1*x1*x1 + b1*x1 + c1)) && Check0((a1*x2*x2 + b1*x2 + c1))))          //�������� ���� �������� ����� 2 �����
            {
                printf("FALED: a1 = %d, b1 = %d, c1 = %d, x1 = %lg, x2 = %lg, SS1 - %lg, SS2 - %lg\n", a1, b1, c1, x1, x2, a1*x1*x1 + b1*x1 + c1, a1*x2*x2 + b1*x2 + c1);
            }
            //assert((a1*x1*x1 + b1*x1 + c1) == 0 && (a1*x2*x2 + b1*x2 + c1) == 0);

        if (n_root == 1)                                                                       //�������� ���� ��������� ����� 1 ������
            if (!(Check0((a1*x1*x1 + b1*x1 + c1))))
            {
                printf("FALED: a1 = %d, b1 = %d, c1 = %d, x1 = %lg, SS1 - %lg\n", a1, b1, c1, x1, a1*x1*x1 + b1*x1 + c1);
            }

            //assert(Check0((a1*x1*x1 + b1*x1 + c1)));

        if (n_root == INF_ROOT)                                                                //�������� ���� ��������� ����� ���������� ������
        {
            int x_1 = 0;
            int j = 0;

            while (j++ < 3)        //3 ��������, ��������� ���� ���������� ��������� ���� ����� ������ 2 ������, ������ �� ����������
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

