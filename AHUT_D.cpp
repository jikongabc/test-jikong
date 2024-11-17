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
const int N = 1e6 + 10;
int n;
int a[N];
int cnt[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int res = 0;
	for(int l = 0, r = 0; r < n; r++){
		cnt[a[r]]++;
		while(cnt[a[r]] > 1){
			cnt[a[l]]--;
			l++;
		}
		res = max(res, r - l + 1);
	}
	cout << res;
	return 0;
}