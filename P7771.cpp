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
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1e5 + 10, M = 2e5 + 10;
int n, m;
int din[N], dout[N];
int ans[M], cnt;
vector<int> edge[N];
// bool st[M];

void dfs(int u){
	while(!edge[u].empty()){
		int t = edge[u].back();
		edge[u].pop_back();
		dfs(t);
	}
	ans[++cnt] = u;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		dout[a]++, din[b]++;
	}
	for(int i = 1 ; i <= n; i++){
		sort(edge[i].rbegin(), edge[i].rend());
	}
	int start = 1;
	int cnt1 = 0, cnt2 = 0;
	for(int i = 1; i <= n; i++){
		if(dout[i] == din[i] + 1){
			start = i;
			cnt1++;
		}
		else if(dout[i] + 1 == din[i]){
			cnt2++;
		}
	}
	if(!(cnt1 == 0 && cnt2 == 0 || cnt1 == 1 && cnt2 == 1)){
    	cout << "No";
    	return 0;
	}

	dfs(start);
	if(cnt < m + 1) cout << "No";
	else{
		for(int i = cnt; i; i--) cout << ans[i] << ' ';
	}
	return 0;
}