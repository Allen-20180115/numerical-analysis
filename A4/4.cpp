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
    for (int k = 0; k < N - 1; k++) //共进行N-1步消元
    {
        int p = k;
        double master = abs(a[k][k]);
        for (int i = k + 1; i < N; i++) //列选主元素
            if (abs(a[i][k]) > master)
            {
                master = abs(a[i][k]);
                p = i;
            }
        for (int i = k; i < N; i++) //对矩阵A的第k行与第p行进行逐列交换,
        {                           //由于两行中前k-1列均为0,
            temp = a[k][i];         //故只需从第k列开始交换即可
            a[k][i] = a[p][i];
            a[p][i] = temp;
        }
        temp = b[k]; //对矩阵b的第k行与第p行进行交换
        b[k] = b[p];
        b[p] = temp;
        for (int i = k + 1; i < N; i++) //消元过程,得到上三角方程组
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
    x[N - 1] = b[N - 1] / a[N - 1][N - 1]; //解x[N-1]
    for (int i = N - 2; i >= 0; i--)       //回代过程,解方程组
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