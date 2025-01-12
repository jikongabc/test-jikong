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


int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	priority_queue<int> q;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		q.push(a[i]);
	}
	LL res = 0;
	while(!q.empty()){
		int t = q.top();
		if(t & 1){
			if(k){
				q.pop();
				q.push(t - 1);
				k--;
			}
			else{
				res += t;
				q.pop();
			}
		}
		else{
			if(m){
				q.pop();
				q.push(t / 2);
				m--;
			}
			else{
				res += t;
				q.pop();
			}
		}
	}
	cout << res << endl;
	return 0;
}