#include <bits/stdc++.h>
using namespace std;

float f(float x)
{
    return x * x * x - 411.791;
}

float ff(float x)
{
    return 3 * x * x;
}

int main()
{
    float x0, x1, e;
    cout << "请输入初值x0及精度e:" << endl;
    cin >> x0 >> e;
    int k = 1;
    while (ff(x0) != 0)
    {
        x1 = x0 - f(x0) / ff(x0);
        printf("x%d=%.6f\n", k++, x1);
        if (abs(x1 - x0) < e)
        {
            printf("\n411.791^(1/3)的近似值为%.6f\n", x1);
            break;
        }
        else
            x0 = x1;
    }
    getchar();
    getchar();
    return 0;
}