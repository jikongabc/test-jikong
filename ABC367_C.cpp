#include <iostream>
#include <vector>
using namespace std;

void generateSequences(int index, int N, int K, const vector<int> &R, vector<int> &current, int currentSum)
{
    if (index == N)
    {
        if (currentSum % K == 0)
        {
            for (int i = 0; i < N; ++i)
            {
                cout << current[i] << (i == N - 1 ? "\n" : " ");
            }
        }
        return;
    }

    for (int i = 1; i <= R[index]; ++i)
    {
        current[index] = i;
        generateSequences(index + 1, N, K, R, current, currentSum + i);
    }
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> R(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> R[i];
    }

    vector<int> current(N, 0);
    generateSequences(0, N, K, R, current, 0);

    return 0;
}
