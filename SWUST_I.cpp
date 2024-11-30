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
// const int N =  ;
int n, k;
string s;

void solve(){
	cin >> n >> k;
	k %= 26;
	cin >> s;
	for(int i = 0; i < n; i++){
		if(s[i] >= 'A' && s[i] <= 'Z') cout << (char)((s[i] - 'A' - k + 26) % 26 + 'A');
		else cout << (char)((s[i] - 'a' - k + 26) % 26 + 'a'); 
	}		
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