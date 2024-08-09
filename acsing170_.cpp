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
const int N = 105;
int n;
int res[N];

bool dfs(int u,int depth){
    if(u==depth)
        return res[u - 1] == n;
    bool st[N] = {0};
    for (int i = u - 1; i >= 0;i--){
        for (int j = i; j >= 0;j--){
            int s = res[i] + res[j];
            if(st[s] || s>n || s<=res[u-1]) continue;
            st[s] = 1;
            res[u] = s;
            if(dfs(u+1,depth))
                return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    res[0] = 1;
    while(cin>>n,n){
        int depth = 1;
        while(!dfs(1,depth))
            depth++;
        for (int i = 0; i < depth;i++)
            cout << res[i] << ' ';
        cout << endl;
    }
    return 0;
}
