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
const int N = 1e5 + 10;
int n, q;
int color[N];
LL tr[N], pre[N]; // pre:维护最大连续白色区间

int lowbit(int x)
{
    return x & -x;
}

void add(int x, LL c, LL tr[])
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}

LL sum(int x, LL tr[])
{
    LL res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

void change(int x)
{
    int t = 1; // 黑变白
    if (color[x] == 1)
        t = -1;              // 白变黑
    color[x] = 1 - color[x]; // 翻转
    add(x, t, tr);
    //更新pre
    int l = x, r = x;
    while (l > 1 && color[l - 1] == color[x])
        l--;
    while (r < n && color[r + 1] == color[x])
        r++;
    int len = r - l + 1;
    for (int i = l; i <= r; i++)
    {
        int val = 0;
        if(color[i]==1)
            val = len;
        add(i, val - sum(x, tr) + sum(x - 1, tr), tr);
    }
}

int get(int l, int r){
    int maxn = 0, cnt = 0;
    for (int i = l; i <= r; ++i){
        if (color[i] == 1){
            cnt++;
            maxn = max(maxn, cnt);
        }
        else{
            cnt = 0;
        }
    }
    return maxn;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        color[i] = 1;  // 1：白  0：黑
        add(i, 1, tr); // 全白
    }
    while(q--){
        int op;
        cin >> op;
        if (op == 1){
            int x;
            cin >> x;
            change(x);
        }
        else if (op == 2){
            int l, r;
            cin >> l >> r;
            cout << get(l, r) << endl;
        }
    }
    return 0;
}
