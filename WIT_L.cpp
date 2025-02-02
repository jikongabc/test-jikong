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
const int N = 55;
const int mod = 998244353;
int n;

LL qmi(int a, int b, int p){
	LL res = 1 % p;
	while(b){
		if(b & 1) res = res * a % p;
		a = a * (LL) a % p;
		b >>= 1;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		cout << qmi(2, n - 1, mod) % mod << endl;
	}
	return 0;
}