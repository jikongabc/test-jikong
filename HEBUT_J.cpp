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
#define endl '\n'
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const double eps = 1e-6;
const double pi = 3.141592653589793;
// const int N =  ;
double a, b, s;

double cal(double r, double a, double b){
	if(r < b / 2.0 || r > a / 2.0) return -1e18;
	double s0 = 0;
	double k = sqrt(r * r - (b / 2.0) * (b / 2.0));
	double x = asin((b / 2.0) / r);
	// double p = 2 * pi - x * 4;
	s0 = b * k + 2.0 * r * r * x;
	return s0;
}

void solve(){
	cin >> a >> b >> s;
	double l = b / 2.0 , r = a / 2.0;
	while(r - l > 1e-12){
		double mid = (l + r) / 2.0;
		if(cal(mid, a, b) < s) l = mid;
		else r = mid;  
	}
	if(r < b / 2.0 || r > a / 2.0 || fabs(cal(r, a, b) - s) > eps){
		cout << -1 << endl;
	}
	else printf("%.12lf\n", r);
}


int main(){
	// ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}