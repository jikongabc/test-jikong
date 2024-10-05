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
const int N = 5e3 + 10;
int n, m;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];
int cnt[N];

void add(int a, int b, int c){
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa(){
    memset(dist, inf, sizeof dist);
    dist[1] = 0;
    queue<int> q;
    for (int i = 1; i <= n;i++){
        st[i] = 1;
        q.push(i);
    }
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            st[t] = 0;
            for (int i = h[t]; i != -1; i = ne[i])
            {
                int j = e[i];
                if (dist[j] > dist[t] + w[i])
                {
                    dist[j] = dist[t] + w[i];
                    cnt[j] = cnt[t] + 1;
                    if (cnt[j] >= n)
                        return true;
                    if (!st[j])
                    {
                        q.push(j);
                        st[j] = 1;
                    }
                }
            }
        }
    return false;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	memset(h, -1, sizeof h);
	// memset(dist, 0x3f, sizeof dist);
	while(m--){
		int a, b, c;
		cin >> a >> b >> c;
		add(b, a, c);
	}
	if(spfa()){
		cout << "NO\n";
		return 0;
	}
	for(int i = 1; i <= n; i++) cout << dist[i] << ' ';
	return 0;
}