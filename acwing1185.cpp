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
const int N = 26;
int n = 26, m;
int din[N], dout[N];
int fa[N];

int find(int x){
	if(fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

void solve(){
	memset(din, 0, sizeof din);
	memset(dout, 0, sizeof dout);
	for(int i = 0; i < n; i++){
		fa[i] = i;
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		string s;
		cin >> s;
		int len = s.size();
		int a = s[0] - 'a', b = s[len - 1] - 'a';
		dout[a]++, din[b]++;
		a = find(a), b = find(b);
		fa[a] = b;
	}
	int start = 0, end1 = 0;
	bool flag = true;
	for(int i = 0; i < n; i++){
		if(din[i] != dout[i]){
			if(din[i] == dout[i] + 1) end1++;
			else if(dout[i] == din[i] + 1) start++;
			else{
				flag = false;
				break;
			}
		}
	}
	if(flag && !(! end1 && ! start || start == 1 && end1 == 1)) flag = false;
	int rep = -1;
	for(int i = 0; i < n ; i++){
		if(din[i]){
			if(rep == -1) rep = find(i);
			else if(rep != find(i)){
				flag = false;
				break;
			}
		}
	}
	if(flag) cout << "Ordering is possible.\n";
	else cout << "The door cannot be opened.\n";
}


int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}