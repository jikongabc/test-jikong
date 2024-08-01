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
typedef pair<int, PII> PIII;
const int N = 2e6 + 10;
int n, k;
LL sum[N];

LL count(int n){
    LL res = 0;
    int t = n ^ (n + 1);
    while(t){
        t >>= 1;
        res++;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    sum[0] = 1;
    for (int i = 1; i <= N;i++){
        sum[i] = sum[i - 1] + count(i);
    }   
    while (T--)
    {
        cin >> n >> k;
        cout << sum[n + k - 1] - sum[n - 1] << endl;
    }
    return 0;
}