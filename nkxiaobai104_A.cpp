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
#define int long long
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1e5 + 10;
int n, x, y, z, k;
LL res = 0;

struct Node{
	int x, y;
}a[N];

bool cmp(Node a, Node b){
	return a.x > b.x;	
}

signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> x >> y >> z >> k;
	a[0] = {x + y, z};
	k += z;
	for(int i = 1; i <= n; i++){
		int xx, yy, zz;
		cin >> xx >> yy >> zz;
		a[i] = {xx + yy, zz};
	}
	sort(a, a + n + 1, cmp);
	int i = 0;
	while(k < a[i].y){
		i++;
	}
	cout << a[i].x;
	return 0;
}