#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 5005;
int n;
double x[N], y[N];
double dist[N];
bool st[N];
int flag;

double get_s(double x1,double y1,double x2,double y2){
    return sqrt((x1 - x2) * (x1 - x2)*1.0 + (y1 - y2) * (y1 - y2)*1.0);
}

double prim(){
    for (int i = 1; i <= n;i++){
        dist[i] = 1e12 * 1.0;
    }
        double res = 0.0;
    for (int i = 0; i < n;i++){
        int t = -1;
        for (int j = 1; j <= n;j++){
            if(!st[j] &&(t==-1|| dist[t]>dist[j]))
                t = j;
        }
        if(i)
            res += dist[t];
        st[t] = 1;
        for (int j = 1; j <= n;j++){
            dist[j] = min(dist[j], get_s(x[t], y[t], x[j], y[j]));
        }
    }
    return res;
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> x[i] >> y[i];
    }
    double ans = prim();
    printf("%.2lf", ans);
    return 0;
}
