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
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int primes[N], cnt;
bool st[N];

void get_primes(int n)
{
    memset(st, 0, sizeof(st));
    cnt = 0;
    for (int i = 2; i <= n; i++){
        if (!st[i]){
            primes[cnt++] = i;
        }
        for (int j = 0; primes[j] <= n / i; j++){
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        get_primes(n);
        bool flag = false;
        for (int i = 0; i < cnt; i++){
            for (int j = i; j < cnt; j++){
                int k = n - primes[i] - primes[j];
                if (k >= 2 && !st[k]){ 
                    cout << primes[i] << ' ' << primes[j] << ' ' << k << endl;
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(!flag)
            cout << -1 << endl;
    }

    return 0;
}
