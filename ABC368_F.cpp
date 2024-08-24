#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 100001;
vector<int> grundy(MAXN, 0);

void preprocess_grundy()
{
    for (int i = 2; i < MAXN; ++i)
    {
        set<int> divisors_grundy;
        for (int j = 2 * i; j < MAXN; j += i)
        {
            divisors_grundy.insert(grundy[j]);
        }
        int g = 0;
        while (divisors_grundy.count(g))
        {
            ++g;
        }
        grundy[i] = g;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    preprocess_grundy();

    int N;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    int nim_sum = 0;
    for (int i = 0; i < N; ++i)
    {
        nim_sum ^= grundy[A[i]];
    }

    if (nim_sum != 0)
    {
        cout << "Anna" << endl;
    }
    else
    {
        cout << "Bruno" << endl;
    }

    return 0;
}
