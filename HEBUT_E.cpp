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
const int N = 10;
const string r = "0123456789ABCDEF";
int n;
string s;


void solve(){
	cin >> s;
	n = s.size();
	int a = 0, b = 0, c = 0;
	for(int i = 0; i < 16; i++){
		if(s[1] == r[i]) a += i * 16;
		if(s[2] == r[i]) a += i;
		if(s[3] == r[i]) b += i * 16;
		if(s[4] == r[i]) b += i;
		if(s[5] == r[i]) c += i * 16;
		if(s[6] == r[i]) c += i;
	}
	a = 255 - a, b = 255 - b, c = 255 - c;
	cout << "#";
	int a1 = a / 16, a2 = a % 16, b1 = b / 16, b2 = b % 16, c1 = c / 16, c2 = c % 16;
	cout << r[a1] << r[a2] << r[b1] << r[b2] << r[c1] << r[c2] << endl; 
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