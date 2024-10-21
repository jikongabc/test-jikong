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
const int N = 1e5 + 10;
int n;
int a[N];
int cnt[N];
unordered_map<int,int> pos;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i = 0; i < v.size(); i++) pos[v[i]] = i + 1;
	int res = 0;
	for(int i = 0; i < n; i++){
		int t = pos[a[i]];
		res += cnt[t];
		cnt[t]++;
		cout << res << ' ';
	}
	return 0;
}