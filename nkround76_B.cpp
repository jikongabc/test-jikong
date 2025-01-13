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


int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> cnt(26, 0);
	// int n = s.size();
	for(int i = 0; i < n; i++){
		cnt[s[i] - 'a'] ++;
	}
	int maxn = 0;
	int res = 0;
	for(int i = 0; i < 26; i++){
		if(cnt[i] > maxn){
			maxn = cnt[i];
			res = i;
		}
	}
	cout << (char)('a' + res);
	return 0;
}