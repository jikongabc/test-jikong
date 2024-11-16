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
const int N = 1000010;
int n, m, k;

struct Tea{
	int a, id;
}teas[N];

bool cmp(Tea a, Tea b){
	return a.a < b.a;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= k; i++){
		cin >> teas[i].a;
		teas[i].id = i; 
	}
	sort(teas + 1, teas + 1 + k, cmp);
	int cnt = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(k - cnt >= n - i) cout << teas[cnt++].id << ' ';
			else cout << 0 << ' ';
		}
		cout << endl;
	}
	return 0;
}