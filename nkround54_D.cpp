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
const int N = 1e3 + 10;
LL a[N];
int dist[N];
int q[N];
int n;
unordered_map<LL, vector<LL>> ma;
vector<vector<LL>> divisor(N);

vector<LL> get_divisors(LL x){
    if (ma.find(x) != ma.end()){
        return ma[x];
    }
    vector<LL> res;
    for (LL i = 1; i * i <= x && i<=N; i++){
        if (x % i == 0){
            if(i<=N)
                res.push_back(i);

            if (i != x / i){
                if(x/i<=N)
                    res.push_back(x / i);
            }
        }
    }
    sort(res.begin(), res.end());
    ma[x] = res;
    return res;
}

void bfs(){
    memset(dist, -1, sizeof dist);
    int hh = 0, tt = 0;
    q[0] = 0;
    dist[0] = 0;
    while (hh<=tt){
        int t = q[hh++];
        for (auto i : divisor[t]){
            int t1 = t - i;
            int t2 = t + i;
            if (t1 >= 0 && dist[t1] == -1){
                dist[t1] = dist[t] + 1;
                q[++tt] = t1;
            }
            if (t2 < n && dist[t2] == -1){
                dist[t2] = dist[t] + 1;
                q[++tt] = t2;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        divisor[i] = get_divisors(a[i]);
    }
    bfs();
    cout << dist[n - 1] << endl;
    return 0;
}
