#include <bits/stdc++.h>
using namespace std;

float f(float x)
{
    return x * x * x - 2 * x - 5;
}

int main()
{
    float a, b, x, e;
    cout << "输入区间端点及精度:" << endl;
    cin >> a >> b >> e;
    cout << "分步结果如下:" << endl;
    do
    {
        x = (a + b) / 2;
        if (f(a) * f(x) < 0)
            b = x;
        else
            a = x;
        printf("x=%.5f,有根区间:[%.5f,%.5f]\n", x, a, b);
    } while (abs(b - a) >= e);
    cout << endl
         << "此约定条件下方程f(x)=0的根为" << x << endl;
    getchar();
    getchar();
    return 0;
}