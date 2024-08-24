#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_operations(int N, vector<int> &A)
{
    int operations = 0;

    while (count_if(A.begin(), A.end(), [](int x)
                    { return x > 0; }) > 1)
    {
        sort(A.begin(), A.end(), greater<int>());

        if (A[0] > 0 && A[1] > 0)
        {
            A[0]--;
            A[1]--;
            operations++;
        }
    }

    return operations;
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    cout << count_operations(N, A) << endl;

    return 0;
}
