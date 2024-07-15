#include <iostream>
#include <algorithm>
#include <cstring>
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
const int N = 1e5 + 10;
int n, k;
int res;
int fa[N], d[N];

int find(int x){
    if(fa[x]!=x){
        int t = find(fa[x]);
        d[x] += d[fa[x]];
        fa[x] = t;
    }    
    return fa[x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    int dd, x, y;
    for (int i = 1; i <= n;i++)
        fa[i] = i;
    while (k--)
    {
        cin >> dd >> x >> y;
        if(x>n || y>n)
            res++;
        else{
            int a = find(x), b = find(y);
            if(dd==1){
                if(a==b && (d[x]-d[y])%3)
                    res++;
                else if(a!=b){
                    fa[a] = b;
                    d[a] = d[y] - d[x];
                }
            }
            else{
                if(a==b && (d[x]-d[y]-1)%3)
                    res++;
                else if(a!=b){
                    fa[a] = b;
                    d[a] = d[y] + 1 - d[x];
                }
            }
        }
    }
    cout << res;
    return 0;
}