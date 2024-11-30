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
const int N = 1010;
int n;
int cnt1[N], cnt2[N];

void solve(){
	memset(cnt1, 0, sizeof cnt1);
	memset(cnt2, 0, sizeof cnt2);
	vector<int> ans;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		cnt1[x]++;
	}
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		cnt2[x]++;
	}
	for(int i = 1; i < N; i++){
		if(cnt1[i] && cnt2[i]){
			ans.push_back(i);
		}
	}
	cout << ans.size() << endl;
	if(!ans.size()) return;
	for(auto i : ans){
		cout << i << ' ';
	}
	cout << endl;
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