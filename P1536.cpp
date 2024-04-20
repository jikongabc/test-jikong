#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string>
#include<map>
#include<set>
#include<unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 10005;
int n, m;
int fa[N];

int find(int x){
    if(fa[x]!=x)
        fa[x] = find(fa[x]);
    return fa[x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> m){
        int ans = 0;
        if(!n)
            break;
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        for(int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            int aa = find(a), bb = find(b);
            fa[aa] = bb;
        }
        for (int i = 1; i <= n;i++){
            if(fa[i]==i)
                ans++;
        }
        cout << ans-1 << endl;
    }

    return 0;
}
