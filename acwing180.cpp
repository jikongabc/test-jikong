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
const int N = 20;
int n;
int a[N];
int t[5][N];

int f(){
    int res = 0;
    for (int i = 0; i < n - 1;i++){
        if(a[i]+1!=a[i+1])
            res++;
    }
    return (res + 2) / 3;
}

bool pd(){
    for (int i = 0; i < n - 1;i++){
        if(a[i]+1!=a[i+1])
            return true;
    }
    return false;
}

bool dfs(int u,int depth){
    if(u+f()>depth)
        return false;
    if(!pd())
        return true;
    for (int len = 1; len <= n;len++){
        for (int l = 0; l + len - 1 <= n;l++){
            int r = l + len - 1;
            for (int k = r + 1; k <= n;k++){
                memcpy(t[u], a, sizeof a);
                int x, y;
                for (x = r + 1, y = l; x <= k;x++,y++)
                    a[y] = t[u][x];
                for (x = l; x <= r;x++,y++)
                    a[y] = t[u][x];
                if(dfs(u+1,depth))
                    return true;
                memcpy(a, t[u], sizeof a);
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for (int i = 0; i < n;i++){
            cin >> a[i];
        }
        int depth = 1;
        while(depth<5 && !dfs(0,depth))
            depth++;
        if(depth==5)
            cout << "5 or more" << endl;
        else
            cout << depth << endl;
    }
    return 0;
}
