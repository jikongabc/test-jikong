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
const int N = 5e5 + 10;
int n, m;

struct Node{
	int a, id;
}p[N];

bool cmp(Node a, Node b){
	if(a.a == b.a) return a.id < b.id;
	return a.a > b.a;
}

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> p[i].a;
		p[i].id = i;
	}
	sort(p + 1, p + 1 + n, cmp);
	int i = 1;
	vector<int> res;
	while(m > 0 && i <= n){
		m -= p[i].a;
		res.push_back(p[i].id);
		i++;
	}
	if(m <= 0){
		cout << "YES\n";
		cout << res.size() << endl;
		for(auto i : res) cout << i << ' ';
	}
	else cout << "NO";
	cout << endl;
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