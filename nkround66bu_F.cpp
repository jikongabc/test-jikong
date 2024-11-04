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
int n, k;
string s;

void solve(){
	cin >> n >> k >> s;
	vector<int> cnt(26, 0);
	for(int i = 0; i < n; i++){
		cnt[s[i] - 'a']++;
	}
	int idx = 0;
	while(k > cnt[idx]) k -= cnt[idx++];
	char c = 'a' + idx;
	vector<int> nxt(n + 1, 0);
	for(int i = n - 1; i >= 0; i--){
		if(i < n - 1 && s[i] == s[i + 1]) nxt[i] = nxt[i + 1];
		else nxt[i] = i + 1; 
	}	
	deque<int> q;
	for(int i = n - 1 ; i >= 0; i--){
		if(s[i] != c) continue;
		if(s[nxt[i]] > s[i] && nxt[i] < n) q.emplace_back(i);
		else q.emplace_front(i);
	}
	k--;
	while(k--){
		q.pop_front();
	}
	int t = q.front();
	s.erase(t, 1);
	cout << c << s << endl;
}


int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}