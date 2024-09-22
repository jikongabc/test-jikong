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
const int N = 2e5 + 10;
int n, q;
int fa[N];
vector<int> v[N];

int find(int x){
    if(fa[x]!=x)
        fa[x] = find(fa[x]);
    return fa[x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n;i++){
        fa[i] = i;
        v[i].push_back(i);
    }
    while(q--){
        int x;
        cin >> x;
        if(x==1){
            int a, b;
            cin >> a >> b;
            int pa = find(a), pb = find(b);
            if(pa!=pb){
                if(v[pa].size()>v[pb].size()){
                    swap(pa, pb);
                }
                fa[pa] = pb;
                v[pb].insert(v[pb].end(), v[pa].begin(), v[pa].end());
                sort(v[pb].begin(), v[pb].end());
                reverse(v[pb].begin(), v[pb].end());
                if(v[pb].size()>10)
                    v[pb].resize(10);
            }
        }
        else{
            int a, k;
            cin >> a >> k;
            a = find(a);
            if(v[a].size()>=k)
                cout << v[a][k - 1] << endl;
            else
                cout << -1 << endl;
        }
    }

    return 0;
}