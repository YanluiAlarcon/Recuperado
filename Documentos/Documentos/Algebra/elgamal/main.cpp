#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int p = 2357, g = 2, PrivA = 1751 , Y_A , m = 2035, k = 1520 , Y_1, Y_2, Y_3, m_1;
    Y_A = pow(g,PrivA);
    Y_A = Y_A % p;
    Y_1 = pow(g,k);
    Y_1 %= p;
    Y_2 = pow(Y_A,k);
    Y_2 *= m;
    Y_2 %= p;
    Y_3 = pow(Y_1,p-1-PrivA);
    Y_3 %= p;
    m_1 = Y_2 * Y_3;
    m_1 %= p;
    cout << m_1;
    return 0;
}
