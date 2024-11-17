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
const int N = 1e7 + 10;
const int mod = 998244353;
int n;
long long a[N], b[N];
int ask[N];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> ask[i];
	}
	b[0] = 1;
	for(int i = 1; i < N; i++){
		if(i == 1 || i == 2) a[i] = 1;
		else a[i] = (a[i - 1] + a[i - 2]) % 998244353;
		b[i] = (b[i - 1] + a[i]) % 998244353;
	}
	LL sum = 0;
	for(int i = 0; i < n; i++){
		sum = (sum + b[ask[i] + 1]) % 998244353;
	}
	cout << sum;
	return 0;
}