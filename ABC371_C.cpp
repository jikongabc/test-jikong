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
#include <bitset>
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 10, M = N * (N - 1) / 2;
int n, m1, m2;
int H[N][N], G[N][N];
int a[N][N];
int res = inf;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> m1;
    for (int i = 0; i < m1;i++){
        int u, v;
        cin >> u >> v;
        G[u][v] = 1, G[v][u] = 1;
    }
    cin >> m2;
    for (int i = 0; i < m2;i++){
        int u, v;
        cin >> u >> v;
        H[u][v] = 1, H[v][u] = 1;
    }
    for (int i = 1; i <= n;i++){
        for (int j = i+1; j <= n;j++){
            cin >> a[i][j];
        }
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    do{
        int sum = 0;
        for (int i = 1; i <= n;i++){
            for (int j = i + 1; j <= n; j++){
                if(G[p[i-1]][p[j-1]]!=H[i][j])
                    sum += a[i][j];
            }
        }
        res = min(res, sum);
    } while (next_permutation(p.begin(),p.end()));
    cout << res;
    return 0;
}