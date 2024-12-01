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
// const int N = ;
LL n, x, y, a, b;

void solve(){
	cin >> n >> x >> y >> a >> b;
	if(x == 1 || y == 1){
		cout << "baka\n";
		return;
	}
	queue<LL> q;
	q.push(n);
	int cnt = 0;
	LL res = 0;
	while(!q.empty()){
		LL t = q.front();
		q.pop();
		if(t % x == 0) q.push(t + a);
		if(t % y == 0) q.push(t + b);
		cnt++;
		if(cnt > 10){
			cout << "baka" << endl;
			return;
		}
		res = max(res, t);
	}
	cout << res << endl;
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