int Check0(double num)                                    //��������� ������� � 0 �������� ��� �������� * == 0 � * != 0 ��� ����� � ��������� ������
{
    if (num < EPS && num > -EPS)
        return 1;
    else
        return 0;
}
