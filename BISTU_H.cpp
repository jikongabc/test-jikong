#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long n;
        cin >> n;
        long long t = n;
        long long n_copy = n;
        long long tt = 0;
        long long p = 10;
        while (n / p > 0)
        {
            tt += n / p;
            p *= 10;
        }
        t += tt;
        cout << t << endl;
    }
    return 0;
}
