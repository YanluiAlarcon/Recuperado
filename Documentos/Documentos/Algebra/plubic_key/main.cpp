#include <iostream>
#include <math.h>

using namespace std;

int mcd(int a, int b)
{
    if (a == 0)
        return b;
    return mcd(b%a, a);
}

int phi(unsigned int m, unsigned int a)
{
    unsigned int result = 1;
    for (int i = 2; i < m; i++)
        if (mcd(i, m) == 1)
            result++;
    cout << "Euler Phi: "<< result << "\n";
    result = pow(a,result);
    result = result % m;
    cout << "Euler Theorem: "<< result << "\n";
}

int main()
{
    int m = 240, a = 2;
    phi(m , a);
    return 0;
}
