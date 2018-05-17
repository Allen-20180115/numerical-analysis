#include <bits/stdc++.h>
using namespace std;

const int n = 5;
double x[n] = {0.4, 0.55, 0.65, 0.8, 0.9};
double y[n] = {0.4175, 0.57815, 0.69657, 0.88811, 1.02652};
double F[n][n]{};

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
    cout << "Newton��ֵ��ʽ��ø��㴦�ĺ���ֵ�ֱ�Ϊ:" << endl;
    for (int i = 0; i < n; i++)
        F[i][0] = y[i];
    for (int j = 1; j < n; j++)
        for (int i = j; i < n; i++)
            F[i][j] = (F[i][j - 1] - F[i - 1][j - 1]) / (x[i] - x[i - j]);
    for (int i = 0; i < cnt; i++)
    {
        Y[i] = F[n - 1][n - 1];
        for (int k = n - 2; k >= 0; k--)
            Y[i] = Y[i] * (X[i] - x[k]) + F[k][k];
        printf("N(%.6lf)=%.6lf\n", X[i], Y[i]);
    }
    delete[] X;
    delete[] Y;
    getchar();
    getchar();
    return 0;
}