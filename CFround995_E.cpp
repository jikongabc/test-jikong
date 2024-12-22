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
#include <climits>
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
#define lnf LLONG_MAX
#define endl '\n'
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const double pi = acos(-1);
// const int N =  ;

struct Node{
	LL price;
	int type; // 1: 正面转负面, 2: 负面转不购买
	bool operator < (const Node &t) const{
		if(price != t.price) return price < t.price;
		return type < t.type;
	}
};

void solve(){
	int n, k;
	cin >> n >> k;
	vector<Node> a(n);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a.push_back({x + 1, 1});
	}	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a.push_back({x + 1, 2});
	}
	sort(a.begin(), a.end());
	int t = n;
	LL bad = 0;
	LL maxn = 0;
	LL pri = 1;
	for(auto &i : a){
		if(pri < i.price){
			if(bad <= k){
				maxn = max(maxn, (LL)(i.price - 1) * (t + bad));
			}
		}
		if(i.type == 1){
			t--;
			bad++;
		}
		else if(i.type == 2){
			bad--;
		}
		pri = i.price;
	}
	cout << maxn << endl;
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