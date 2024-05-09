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
const int N = 110;
int n;
int path[N];

bool dfs(int u,int k){
    if(u==k)
        return path[u - 1] == n;
    bool st[N] = {0};
    for (int i = u - 1; i >= 0;i--){
        for (int j = i; j >= 0;j--){
            int s = path[i] + path[j];
            if(s>n || s<=path[u-1] || st[s])
                continue;
            st[s] = 1;
            path[u] = s;
            if(dfs(u+1,k))
                return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    path[0] = 1;
    while(cin>>n,n){
        int k = 1;
        while(!dfs(1,k))
            k++;
        for (int i = 0; i < k;i++)
            cout << path[i] << ' ';
        cout << endl;
    }
    return 0;
}