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
const int N = 2e5 + 10;
int n;
int p[N];
unordered_map<int, int> ma;
int t = 0;

struct node{
    int u, v, e;
} pp[N];

int get(int x){
    if(ma.count(x)==0)
        ma[x] = ++t;
    return ma[x];
}

int find(int x){
    if(p[x]!=x)
        p[x] = find(p[x]);
    return p[x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        bool flag = 0;
        t = 0;
        ma.clear();
        for (int i = 0; i < n; i++)
        {
            int u, v, e;
            cin >> u >> v >> e;
            int pu = get(u), pv = get(v);
            pp[i] = {pu, pv, e};
        }
        for (int i = 1; i <= t;i++)
            p[i] = i;
        for (int i = 0; i < n; i++)
        {
            if (pp[i].e == 1)
            {
                int a = find(pp[i].u), b = find(pp[i].v);
                if(a!=b)
                    p[a] = b;
            }
        }
        for (int i = 0; i < n;i++){
            if(pp[i].e==0){
                int a = find(pp[i].u), b = find(pp[i].v);
                if(a==b)
                    flag = 1;
            }
        }
        if(flag)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}