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

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int lcm(int a,int b)
{
	return a * b / gcd(a, b);
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	unordered_map<int, int> cnt;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	// sort(a.begin(), a.end());
	int res = 0;
	for(auto &[a, b] : cnt){
		if(b & 1) res++;
		else res += 2;
	}
	cout << res << endl;
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