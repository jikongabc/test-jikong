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
int stk[N], top;
string s;
int n;
int cnt;
int res[N];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	cin >> s;
	s = " " + s;
	for(int i = 1; i <= n * 2; i++){
		if(s[i] == '('){
			stk[++top] = ++cnt;
		}
		else{
			if(top){
				res[stk[top]] = top;
				top--;
			}
			else{
				cout << -1 << endl;
				return 0;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout << n - res[i] << ' ';
	}
	return 0;
}