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
string a, b;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> a >> b;
	if(~a.find(".")) a += "00000000";
	else a += ".00000000";
	if(~b.find(".")) b += "00000000";
	else b += ".00000000";
	a.erase(a.find(".") + 7);
	b.erase(b.find(".") + 7);
	if(a == b) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}