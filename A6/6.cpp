#include <bits/stdc++.h>
using namespace std;

const int n = 5;
double x[n] = {0.4, 0.55, 0.65, 0.8, 0.9};
double y[n] = {0.4175, 0.57815, 0.69657, 0.88811, 1.02652};

int main()
{
    int cnt;
    cout << "����f(x)�ĺ���������:" << endl;
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << y[i] << " ";
    cout << endl;
    cout << "�������ֵ��ĸ���:";
    cin >> cnt;
    double *X = new double[cnt];
    double *Y = new double[cnt];
    cout << "���������ֵ��:";
    for (int i = 0; i < cnt; i++)
        cin >> X[i];
    for (int i = 0; i < cnt; i++)
        Y[i] = 0.0;
    cout << "Lagrange��ֵ��ʽ��ø��㴦�ĺ���ֵ�ֱ�Ϊ:" << endl;
    for (int i = 0; i < cnt; i++)
    {
        for (int k = 0; k < n; k++)
        {
            double t = 1;
            for (int j = 0; j < n; j++)
            {
                if (j != k)
                    t *= (X[i] - x[j]) / (x[k] - x[j]);
            }
            Y[i] += t * y[k];
        }
        printf("L(%.6lf)=%.6lf\n", X[i], Y[i]);
    }
    delete[] X;
    delete[] Y;
    getchar();
    getchar();
    return 0;
}