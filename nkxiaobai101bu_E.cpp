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
#include <bitset>
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
#define int long long
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1e6 + 10;
int n;
int a[N];
int cnt[N];
int res[N];
bool st[N];
int spf[N]; // 最小质因子
int e[N];   // 最小质因子的指数
int r[N];   // 除去最小质因子的最高次幂后剩余的数

vector<int> pri;
bool not_prime[N];
int d[N], num[N];

void pre(int n)
{
    d[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (!not_prime[i])
        {
            pri.push_back(i);
            d[i] = 2;
            num[i] = 1;
        }
        for (int pri_j : pri)
        {
            if (i * pri_j > n)
                break;
            not_prime[i * pri_j] = true;
            if (i % pri_j == 0)
            {
                num[i * pri_j] = num[i] + 1;
                d[i * pri_j] = d[i] / num[i * pri_j] * (num[i * pri_j] + 1);
                break;
            }
            num[i * pri_j] = 1;
            d[i * pri_j] = d[i] * 2;
        }
    }
}

int get_divisors(int x)
{
    unordered_map<int, int> primes;
    for (int i = 2; i <= x / i; i++)
    {
        while (x % i == 0)
        {
            x /= i;
            primes[i]++;
        }
    }
    if (x > 1)
        primes[x]++;
    LL res = 1;
    for (auto p : primes)
        res = res * (p.second + 1);
    return res;
}

void compute_divisors(int n)
{
    cnt[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (spf[i] == 0)
        {
            spf[i] = i;
            e[i] = 1;
            r[i] = 1;
            cnt[i] = 2;
        }
        else
        {
            int p = spf[i];
            if (spf[i / p] == p)
            {
                e[i] = e[i / p] + 1;
                r[i] = r[i / p];
            } 
            else
            {
                e[i] = 1;
                r[i] = i / p;
            }
            cnt[i] = cnt[r[i]] * (e[i] + 1);
        }
        // 对于每个 i，spf[i * p] 只更新一次，保证线性复杂度
        for (int j = i * 2; j <= n; j+=i)
        {
            if (spf[j] == 0)
                spf[j] = i;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int maxn = 0;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        st[a[i]] = 1;
        maxn = max(maxn, a[i]);
    }
    // for (int i = 1; i <= maxn;i++){
    //     cnt[i] = get_divisors(i);
    //     // cout << cnt[i] << ' ';
    // }
    // cout << endl;
    for (int i = 1; i <= maxn; i++)
    {
        if(!st[i])
            continue;
        for (int j = i; j <= maxn;j+=i)
            res[j]++;
    }
    // compute_divisors(n);
    pre(maxn);
    int ans = 0;
    for (int i = 1; i <= maxn;i++){
        if(st[i] && d[i]==res[i]){
            ans++;
            // cout << i << ' ';
        }
    }
    // for (int i = 1; i <= 100;i++)
    //     cout << cnt[i] << ' ';
        // cout << cnt[8] << ' ' << res[8] << endl;
        // cout << endl;
        cout << ans;
        // cout << endl;
        // for (int i = 1; i <= n;i++)
        //     cout << cnt[i] << ' ';
        return 0;
}