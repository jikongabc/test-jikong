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
typedef pair<int, PII> PIII;
const int N = 1e5 + 10;
int n, m;
int fa[N];
int res;

int find(int x){
    if(fa[x]!=x)
        fa[x] = find(fa[x]);
    return fa[x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= 2 * n;i++)
        fa[i] = i;
        string op;
    int a, b;
    while(m--){
        cin >> op;
        cin >> a >> b;
        int pa = find(a), pb = find(b), da = find(a + n), db = find(b + n);
        if(op=="F"){
            fa[pa] = pb;
        }
        else{
            fa[da] = pb;
            fa[db] = pa;
        }   
    }
    for (int i = 1; i <= n;i++){
        if(fa[i]==i)
            res++;
    }
    cout << res;
    return 0;
}