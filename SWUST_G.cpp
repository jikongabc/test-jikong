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
// const int N =  ;

double get_dist(int a, int b, int c, int d){
	return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

void solve(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	double dist1 = get_dist(-a, b, c, d);
	double dist2 = get_dist(a, -b, c, d);
	if(dist1 < dist2){
		cout << "y" << endl;
	}
	else cout << "x" << endl;
}


int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}