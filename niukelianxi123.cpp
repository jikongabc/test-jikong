// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdio>
// #include <queue>
// #include <deque>
// #include <vector>
// #include <map>
// #include <set>
// #include <unordered_map>
// #include <string>
// using namespace std;
// const int N = 1e5 + 10;
// int main()
// {
//     int n;
//     cin >> n;
//     char ch[N];
//     cin >> ch;
//     for (int i = 0; i < n / 2 +1; i++)
//     {
//         cout << ch[i];
//     }
//     return 0;
// }

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;

    int half_length = ceil(N / 2.0);

    for (int i = 0; i < half_length; ++i)
    {
        cout << S[i];
    }

    cout << endl;

    return 0;
}
