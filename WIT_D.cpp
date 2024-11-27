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
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const int N = 1e5 + 10, M = 3010;
const int mod = 998244353;
int n;
int a[N];
int dp[M][N]; //dp[i][j] : 以i结尾的公比为j的等比数列的数量
vector<int> g[M]; //存约数
int f[M]; //f[i] : 以i结尾的长度为1的等比数列的个数


int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i < M; i++){
		for(int j = i; j < M; j += i){
			g[j].push_back(i);
		}
	}
	int res = 0;
	for(int i = 1; i <= n; i++){
		for(int j : g[a[i]]){
			res = (res + f[a[i] / j]) % mod;
			res = (res + dp[a[i] / j][j] % mod);
			dp[a[i]][j] = (dp[a[i]][j] + dp[a[i] / j][j] + f[a[i] / j]) % mod;
		}
		f[a[i]]++;
	}
	cout << (res + n) % mod << endl;
	return 0;
}