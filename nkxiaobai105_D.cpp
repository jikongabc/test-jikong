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
#define endl '\n'
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const int N = 200005;

vector<int> edges[N];
int colors[N];   
bool st[N]; 
void dfs(int u, vector<int> &v)
{
    st[u] = true;
    v.push_back(u);
    for (int i : edges[u])
    {
        if (!st[i])
        {
            dfs(i, v);
        }
    }
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> colors[i];
    }
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    int minn = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!st[i])
        {
            vector<int> v;
            dfs(i, v);
            unordered_map<int, int> ma;
            for (int j : v)
            {
                ma[colors[j]]++;
            }
            int maxn = 0;
            for (auto &i : ma)
            {
                maxn = max(maxn, i.second);
            }
            minn += v.size() - maxn;
        }
    }

    cout << minn << endl;
	return 0;
}