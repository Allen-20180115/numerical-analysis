#include <bits/stdc++.h>
using namespace std;

const int n = 3;
double a[n][n] = {{8, -3, 2}, {4, 11, -1}, {6, 3, 12}};
double b[n] = {20, 33, 36};
double x[n]{}, y[n]{};

int main()
{
    double e, max;
    cout << "雅可比迭代法求解方程组:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << b[i] << endl;
    }
    cout << "请输入该方程组解的精度e:";
    cin >> e;
    cout << "每次迭代结果如下:" << endl;
    int k = 0;
    for (;;)
    {
        max = 0.0;
        k++;
        for (int i = 0; i < n; i++)
        {
            double sum = 0.0;
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                sum += a[i][j] * x[j];
            }
            y[i] = (b[i] - sum) / a[i][i];
            printf("x%d(%d)=%.7lf ", i + 1, k, y[i]);
            if (abs(x[i] - y[i]) > max)
                max = abs(x[i] - y[i]);
        }
        printf("\n");
        if (max < e)
        {
            cout << "满足该精度的方程组的近似解:" << endl;
            for (int i = 0; i < n; i++)
                printf("x%d=%.7lf\n", i + 1, y[i]);
            break;
        }
        for (int i = 0; i < n; i++)
            x[i] = y[i];
    }
    getchar();
    getchar();
    return 0;
}