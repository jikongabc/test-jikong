#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
typedef pair<PII, int> PIII;
const int N = 50005;
bool st[N];

struct node{
    int x,  y;
} p[N];

bool cmp(node a,node b){
    if(a.x!=b.x)
        return a.x < b.x;
    return a.y < b.y;
}

int n, k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n;i++){
        int t;
        cin >> t;
        p[i] = {t, i};
    }
    sort(p, p + n, cmp);
    for (int i = 1; i <= n;i++){
        if(p[i].x==p[i-1].x && abs(p[i].y-p[i-1].y)<=k)
            st[p[i].x] = 1;
    }
    int res = 0;
    for (int i = 0; i < n;i++){
        if(st[i])
            res ^= i;
    }
    cout << res;
    return 0;
}