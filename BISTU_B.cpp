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
const int N = 2e5 + 10;
const int mod = 998244353;
int n, k;

LL qmi(int a, int b, int p){
	LL res = 1 % p;
	while(b){
		if(b & 1) res = res * a % p;
		a = a * (LL) a % p;
		b >>= 1;
	}
	return res;
}

LL inv(int a){
	return qmi(a, mod - 2, mod);
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	if(k == 1){
		cout << inv(n);
	}
	else{
		// LL res = 0, ans = inv(n);  
		// // ans: 当前累计的精灵进入编号为k的胶囊的概率总和
		// // res: 当前编号的精灵进入编号为k的胶囊的概率
		// for(int i = 1; i < k - 1; i++){
		// 	res = (ans * inv(n - i)) % mod;
		// 	ans = (ans + res) % mod;
		// }
		// cout << (1 - ans + mod) % mod << endl;
		cout << ((n - k + 1) % mod * inv(n - k + 2) % mod) % mod << endl;
		//n - k + 1 : 剩余胶囊中k号胶囊的有效选择
		//n - k + 2 : 第k号精灵随机进入剩余胶囊的总可能性
	}
	
	return 0;
}