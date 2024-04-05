#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 105;
int n;
double t;

struct node{
    double m, v;
    double pri;
} p[N];

bool cmp(node a,node b){
    return a.pri > b.pri;
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    cin >> n >> t;
    for (int i = 0; i < n;i++){
        cin >> p[i].m >> p[i].v;
        p[i].pri = p[i].v/ p[i].m;
    }
    sort(p, p + n, cmp);
    int k = 0;
    // for (int i = 0; i < n;i++){
    //     cout << p[i].m << ' ' << p[i].v << ' ' << p[i].pri << endl;
    // }
        double ans = 0;
    while(p[k].m<=t){
        ans += p[k].v;
        t -= p[k].m;
        k++;
    }
    ans += p[k].pri * t;
    printf("%.2lf", ans);
    return 0;
}
