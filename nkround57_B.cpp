#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int n;
string s;
vector<int> tree[N];
bool st[N];

int dfs(int u){
    st[u] = true;
    int cnt = 0;
    for (int i : tree[u]){
        if (!st[i]){
            if (s[u] == s[i])
                cnt++;
            else
                cnt += dfs(i); 
        }
    }
    return cnt;
}

int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int res = 0;
    for (int i = 0; i < n; i++){
        if (!st[i])
            res += dfs(i); 
    }
    cout << res << endl;
    return 0;
}
