#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
string s = "aeiou";

void solve()
{
    int n;
    cin >> n;
    int t = n / 5;
    int x = n % 5;
    for (int i = 0; i < 5;i++){
        if(x){
            for (int j = 0; j < t + 1;j++)
                cout << s[i];
            x--;
        }
        else{
            for (int j = 0; j < t; j++)
                cout << s[i];
        }
    }
    cout << endl;
}

const int N = 3e5 + 10;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}