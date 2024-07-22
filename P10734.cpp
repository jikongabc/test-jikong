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
int n, q;
int fa[N];
int d[N];

int find(int x){
    if(fa[x]!=x){
        int t = find(fa[x]);
        d[x] += d[fa[x]];
        fa[x] = t;
    }
    return fa[x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n;i++)
        fa[i] = i;
    while (q--)
    {
        string op;
        cin >> op;
        int a, b;
        cin >> a >> b;
        int pa = find(a), pb = find(b);
        if (op == "A"){
            if(pa!=pb){
                fa[pa] = pb;
                d[pa] = d[b] - d[a] + 1;
            }
        }
        else if (op == "R"){
            if(pa!=pb){
                fa[pa]=pb;
                d[pa] = d[b] - d[a];
            }
        }
        else{
            if(pa==pb){
                if(((d[a]-d[b])%2+2)%2)
                    cout << "A" << endl;
                else
                    cout << "R" << endl;
            }
            else
                cout << "?" << endl;
        }
    }
    return 0;
}