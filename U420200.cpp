#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <set>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
const int N = 1e5 + 10;
double l, r, x1, y11, x2, y2, x3, y3;

double x_ab(double x1,double y11,double x2,double y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y11 - y2) * (y11 - y2));
}

double s_abc(double a,double b,double c){
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
double ans = 9999999999.0;
double mid;
double res;

void solve(){
    double ab = x_ab(x1, y11, x2, y2), ac = x_ab(x1, y11, x3, y3), bc = x_ab(x2, y2, x3, y3);
    // double aa = mid * ab, bb = mid * ac, cc = mid * bc;
    double S = s_abc(ab, bc, ac);
    double sin_a = (2.0 * S) / (ac * ab);
    double sin_b = (2.0 * S) / (bc * ab);
    double sin_c = (2.0 * S) / (bc * ac);
    double S1 = 0.5 * mid *(1 - mid) * ac * ab * sin_a, S2 = 0.5 * mid * (1 - mid) * ab * bc * sin_b, S3 = 0.5 * mid * (1 - mid) * bc * ac * sin_c;
    res = S - S1 - S2 - S3;
    // res = s_abc(aa, bb, cc);
}
//2*s/a*b=sin_c
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    cin >> l >> r >> x1 >> y11 >> x2 >> y2 >> x3 >> y3;
    while(l<=r){
        mid = (l + r)/ 2.0;
        mid = l;
        l += 0.0001;
        solve();
        ans = min(ans, res);
    }
    printf("%.12lf", ans);
    return 0;
}