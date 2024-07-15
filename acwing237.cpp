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
const int N = 2e5+10;
int n;
int fa[N];
unordered_map<int, int> ma;
int t;

struct node{
    int i, j, e;
} p[N];

int find(int x){
    if(fa[x]!=x)
        fa[x] = find(fa[x]);
    return fa[x];
}

bool cmp(node a,node b){
    return a.e < b.e;
}

int get(int x){
    if(ma.count(x)==0)
        ma[x] = ++t;
    return ma[x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        bool flag = 0;
        ma.clear();
        t = 0;
        cin >> n;
        for (int k = 0; k < n;k++)
        {
            int i, j, e;
            cin >> i >> j >> e;
            p[k] = {get(i), get(j), e};
        }
        for (int k = 1; k <= t;k++)
            fa[k] = k;
        for (int k = 0; k < n;k++){
            int i = p[k].i, j = p[k].j, e = p[k].e;
            i = find(i), j = find(j);
            if(e){
                if(i!=j){
                    fa[i] = j;
                }
            }
        }
        for (int k = 0; k < n;k++){
            int i = p[k].i, j = p[k].j, e = p[k].e;
            i = find(i), j = find(j);
            if(!e){
                if(i==j){
                    flag = 1;
                    break;
                }
            }
        }
            if (!flag)
                cout << "YES\n";
            else
                cout << "NO\n";
    }

    return 0;
}