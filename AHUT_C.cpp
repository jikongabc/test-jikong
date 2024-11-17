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
const int N = 2e5 + 10;
int n;
int a[N];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int m;
	cin >> m;
	set<int> se;
	while(m--){
		se.clear();
		int mp[N] = {0};
		string s;
		cin >> s;
		if(s.size() != n){
			cout << "NO\n";
			continue;
		}
		int flag = 0;
		for(int i = 0; i < n; i++){
			if(!mp[s[i]] && se.count(a[i]) == 0){
				mp[s[i]] = a[i];
				se.insert(a[i]);
			}
			else if(mp[s[i]] != a[i]){
				cout << "NO\n";
				flag = 1;
				break;
			}
		}
		if(!flag) cout << "YES\n";
	}	
	return 0;
}