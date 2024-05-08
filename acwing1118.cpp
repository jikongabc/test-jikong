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
const int N = 15;
int n;
int a[N];
vector<int> g[N];
int ans = N;

int gcd(int a,int b){
    return b ? gcd(b, a % b) : a;
}

bool check(vector<int>& v,int x){
    for (int i = 0; i < v.size();i++){
        if(gcd(v[i],x)>1)
            return false;
    }
    return true;
}

void dfs(int u,int k){
    if(k>ans)
        return;
    if(u>=n){
        ans = k+1;
        return;
    }
    for (int i = 0; i <= k;i++){
        if(check(g[i],a[u])){
            g[i].push_back(a[u]);
            dfs(u + 1, k);
            g[i].pop_back();
        }
    }
    
    g[k + 1].push_back(a[u]);
    dfs(u + 1, k + 1);
    g[k + 1].pop_back();
    

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}


