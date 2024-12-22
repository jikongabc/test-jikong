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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    for(int i = 0; i < m; i++){
    	cin >> a[i];
    }
    vector<int> q(k);
    for(int i = 0; i < k; i++){
    	cin >> q[i];
    }
    int t = n - k;
    string res = "";
    if(t > 1) res = string(m, '0');
	else if(t == 1){
    	int x = 1;
    	for(int i = 0; i < k; i++){
    		if(q[i] == x){
    			x++;
    		}
    		else if(q[i] > x) break;
    	}
    	if(x > n) x = n;
    	for(int i = 0; i < m; i++){
    		if(a[i] == x) res += '1';
    		else res += '0';
    	}
    }
    else res = string(m, '1');
    cout << res << endl;

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
