#include <bits/stdc++.h>
using namespace std;

float f(float x)
{
    return pow(4 * x + 2, 0.2);
}

int main()
{
    float x0, x1, e;
    cout << "�����ֵx0������:" << endl;
    cin >> x0 >> e;
    int k = 1;
    for (;;)
    {
        x1 = f(x0);
        printf("x%d=%.4f\n", k++, x1);
        if (abs(x1 - x0) < e)
        {
            printf("\n����x^5-4x-2=0����С����Ϊ(����4λС��):%.4f\n", x1);
            break;
        }
        else
            x0 = x1;
    }
    getchar();
    getchar();
    return 0;
}