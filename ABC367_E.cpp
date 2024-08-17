#include <iostream>
#include <vector>

using namespace std;

vector<int> apply_permutation(const vector<int> &P, const vector<int> &A)
{
    int N = P.size();
    vector<int> result(N);
    for (int i = 0; i < N; ++i)
    {
        result[i] = A[P[i]];
    }
    return result;
}

vector<int> permute(vector<int> P, vector<int> A, long long K)
{
    int N = P.size();
    vector<int> result = A;

    while (K > 0)
    {
        if (K % 2 == 1)
        {
            result = apply_permutation(P, result);
        }
        P = apply_permutation(P, P);
        K /= 2;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    long long K;
    cin >> N >> K;

    vector<int> X(N), A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> X[i];
        X[i]--; 
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    vector<int> result = permute(X, A, K);

    for (int i = 0; i < N; ++i)
    {
        cout << result[i] << (i < N - 1 ? " " : "\n");
    }

    return 0;
}
