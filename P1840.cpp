#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
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
    int n, m;
    cin >> n >> m;
    int res = n;
    for (int i = 0; i <= n+1;i++)
        fa[i] = i;
    while (m--)
    {
        int a, b;
        cin >> a>> b;
        b = find(b);
        while(a<=b){
            // if(a!=b && find(a)==b)
            //     break;
            fa[b] = find(fa[b - 1]);
            res--;
            b = find(b);
        }
        cout << res << endl;
    }
    return 0;
}