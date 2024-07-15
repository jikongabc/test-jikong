#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 40010;

int n, m;
int fa[N];
int res;

int get(int x,int y){
    return (x - 1) * n + y;
}

int find(int x){
    if(fa[x]!=x)
        fa[x] = find(fa[x]);
    return fa[x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= N;i++)
        fa[i] = i;
    bool flag = 0;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        char c;
        cin >> c;
        int a = get(x, y), b;
        if (c == 'D')
            b = get(x + 1, y);
        else
            b = get(x, y + 1);
        a = find(a), b = find(b);
        if (fa[a] != b)
            fa[a] = b;
        else{
            flag = 1;
            res = i;
            break;
        }    
    }
    if(flag)
        cout << res;
    else
        cout << "draw";

    return 0;
}
