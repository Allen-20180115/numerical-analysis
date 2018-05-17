#include <bits/stdc++.h>
using namespace std;

const int N = 3;
double a[N][N] = {{2, 2, 3}, {4, 7, 7}, {-2, 4, 5}};
double b[N] = {3, 1, -7};
double x[N]{};

int main()
{
    double temp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << a[i][j] << " ";
        cout << b[i] << endl;
    }
    cout << endl;
    for (int k = 0; k < N - 1; k++) //������N-1����Ԫ
    {
        int p = k;
        double master = abs(a[k][k]);
        for (int i = k + 1; i < N; i++) //��ѡ��Ԫ��
            if (abs(a[i][k]) > master)
            {
                master = abs(a[i][k]);
                p = i;
            }
        for (int i = k; i < N; i++) //�Ծ���A�ĵ�k�����p�н������н���,
        {                           //����������ǰk-1�о�Ϊ0,
            temp = a[k][i];         //��ֻ��ӵ�k�п�ʼ��������
            a[k][i] = a[p][i];
            a[p][i] = temp;
        }
        temp = b[k]; //�Ծ���b�ĵ�k�����p�н��н���
        b[k] = b[p];
        b[p] = temp;
        for (int i = k + 1; i < N; i++) //��Ԫ����,�õ������Ƿ�����
        {
            double r = a[i][k] / a[k][k];
            b[i] -= r * b[k];
            for (int j = k; j < N; j++)
                a[i][j] -= r * a[k][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%15lf", a[i][j]);
        printf("%15lf\n", b[i]);
    }
    printf("\n");
    x[N - 1] = b[N - 1] / a[N - 1][N - 1]; //��x[N-1]
    for (int i = N - 2; i >= 0; i--)       //�ش�����,�ⷽ����
    {
        double sum = 0;
        for (int j = i + 1; j < N; j++)
            sum += a[i][j] * x[j];
        x[i] = (b[i] - sum) / a[i][i];
    }
    for (int i = 0; i < N; i++)
        printf("x%d=%10.7lf\n", i + 1, x[i]);
    getchar();
    getchar();
    return 0;
}