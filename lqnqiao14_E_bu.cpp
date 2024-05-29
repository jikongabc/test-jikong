#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<double, int> PDI;
const int N = 2005;
int n;
int x[N], y[N];
set<PII> s;

double get_dist(int x,int y,int x2,int y2){
    return (double)sqrt((LL)(x - x2) * (x - x2) + (LL)(y - y2) * (y - y2));
}

double pd(int x,int y,int x2,int y2){
    int xx = 2 * x - x2;
    int yy = 2 * y - y2;
    if(s.count({xx,yy}))
        return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> x[i] >> y[i];
        s.insert({x[i], y[i]});
    }
    LL res = 0;
    map<double, LL> ma;
    for (int i = 0; i < n;i++){
        LL cnt = 0;
        for (int j = 0; j < n;j++){
            if(i==j)
                continue;
            double dist = get_dist(x[i], y[i], x[j], y[j]);
            res += ma[dist];
            ma[dist]++;
            if(pd(x[i],y[i],x[j],y[j]))
                cnt++;
        }
        res -= (cnt / 2);
        ma.clear();
    }
    cout << res;
    return 0;
}
