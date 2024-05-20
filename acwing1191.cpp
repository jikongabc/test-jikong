#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 205;
int n;
int h[N], e[N], ne[N], idx;
int d[N];
int q[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort(){
    int hh = 0, tt = -1;
    for (int i = 1; i <= n;i++){
        if(!d[i])
            q[++tt] = i;
    }
    while(hh<=tt){
        int t = q[hh++];
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            if(--d[j]==0)
                q[++tt] = j;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n;i++){
        int t;
        while(cin>>t,t){
            add(i, t);
            d[t]++;
        }
    }
    topsort();
    for (int i = 0; i < n;i++)
        cout << q[i] << ' ';
    return 0;
}