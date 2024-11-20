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
typedef pair<char, int> PCI;
const int N = 1e6 + 10;
string a, b;
int arr[N], tr[N];
int n;

int lowbit(int x){
	return x & -x;
}

int sum(int x){
	int res = 0;
	for(int i = x; i; i -= lowbit(i)) res += tr[i];
	return res;
}

void add(int x, int c){
	for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

void solve(){
	cin >> a >> b;
	n = a.size();
	int cnt1[26] = {0}, cnt2[26] = {0};
	for(int i = 0; i < n; i++){
		cnt1[a[i] - 'a']++;
		cnt2[b[i] - 'a']++;
	}	
	for(int i = 0; i < 26; i++){
		if(cnt1[i] != cnt2[i]){
			cout << "NO\n";
			return;
		}
	}
	bool flag = false;
	for(int i = 0; i < 26; i++){
		if(cnt1[i] > 1){
			flag = true;
			break;
		}
	}
	if(flag){
		cout << "YES\n";
		return;
	}
	// cout << "----" << endl; 
	map<char, int> ma1, ma2;
	vector<PCI> v1(n), v2(n);
	for(int i = 0; i < n; i++){
		v1[i] = {a[i], ++ma1[a[i]]};
		v2[i] = {b[i], ++ma2[b[i]]};
	} 
	map<PCI, int> pos;
	for(int i = 0; i < n; i++){
		pos[v2[i]] = i + 1;
	}
	for(int i = 1; i <= n; i++){
		arr[i] = pos[v1[i - 1]];
	}
	memset(tr, 0, sizeof tr);
	LL cnt = 0;
	for(int i = n; i >= 1; i--){
		cnt += sum(arr[i] - 1);
		add(arr[i], 1);
	}
	if(cnt & 1) cout << "NO\n";
	else cout << "YES\n";
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