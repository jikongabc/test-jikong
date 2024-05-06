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
typedef pair<double, int> PDI;
const int N = 1e5 + 10;
int n, k;
int dist[N];
int q[N];

int move(int x,int i){
    if(i==0)
        return x - 1;
    if(i==1)
        return x + 1;
    if(i==2)
        return x * 2;
}

int bfs(){
    memset(dist, -1, sizeof dist);
    q[0] = n;
    int hh = 0, tt = 0;
    dist[n] = 0;
    while(hh<=tt){
        int x = q[hh++];
        for (int i = 0; i < 3;i++){
            int x1 = move(x, i);
            if(x1<0 || x1>=N)
                continue;
            if(dist[x1]>=0)
                continue;
            q[++tt] = x1;
            dist[x1] = dist[x] + 1;
            if(x1==k)
                return dist[x1];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    cout << bfs();
    return 0;
}