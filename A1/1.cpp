#include <bits/stdc++.h>
using namespace std;

float f(float x)
{
    return x * x * x - 2 * x - 5;
}

int main()
{
    float a, b, x, e;
    cout << "��������˵㼰����:" << endl;
    cin >> a >> b >> e;
    cout << "�ֲ��������:" << endl;
    do
    {
        x = (a + b) / 2;
        if (f(a) * f(x) < 0)
            b = x;
        else
            a = x;
        printf("x=%.5f,�и�����:[%.5f,%.5f]\n", x, a, b);
    } while (abs(b - a) >= e);
    cout << endl
         << "��Լ�������·���f(x)=0�ĸ�Ϊ" << x << endl;
    getchar();
    getchar();
    return 0;
}