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
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1e5 + 10;
int n, m;
int op;
int fa[N];
int d[N];
unordered_map<int, int> ma;

int find(int x){
    if(fa[x]!=x){
        int t = find(fa[x]);
        d[x] += d[fa[x]];
        fa[x] = t;
    }
    return fa[x];
}

int get(int x){
    if(ma.count(x)==0)
        ma[x] = op++;
    return ma[x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i <= N;i++)
        fa[i] = i;
    cin >> n >> m;
    int l, r;
    string s;
    int res = m;
    for(int i=1;i<=m;i++){
        cin >> l >> r >> s;
        l = get(l - 1), r = get(r);
        int pl = find(l), pr = find(r);
        int t = 0;
        if(s=="odd")
            t = 1;
        if(pl==pr){
            if(((d[r]-d[l])%2+2)%2!=t){
                res = i - 1;
                break;
            }
        }
        else{
            fa[pl] = pr;
            d[pl] = (d[r] - d[l] + t) % 2;
        }
    }
    cout << res << endl;
    return 0;
}