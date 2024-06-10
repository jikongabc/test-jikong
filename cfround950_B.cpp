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
using namespace std;
using LL = long long;
typedef pair<int, int> PII;
const int N = 205;
int n, m, k;

struct node{
    int a, id;
} p[N];

bool cmp(node a,node b){
    return a.a > b.a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m >> k;
        map<int, int> ma;
        int t;
        for (int i = 1; i <= n;i++){
            cin >> p[i].a;
            p[i].id = i;
            if(i==m)
                t = p[i].a;
            ma[p[i].a]++;
        }
        sort(p + 1, p + n + 1, cmp);
        if(p[k].a>t)
            cout << "NO\n";
        else if (p[k].a<t || p[k].a==t && p[k].a!=p[k+1].a)
            cout << "YES\n";
        else
            cout << "MAYBE\n";
    }
    return 0;
}