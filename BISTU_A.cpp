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
// const int N =  ;
int a, b, c;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> a >> b >> c;
	if(a == b) cout << c;
	else if(a == c) cout << b;
	else cout << a;
	return 0;
}