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
const int N = 1e5 + 10;
int n;
int a[N];
LL sum;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n + 1; i++){
		sum += abs(a[i] - a[i - 1]);
	}
	for(int i = 1; i <= n; i++){
		LL res = sum - abs(a[i] - a[i - 1]) - abs(a[i + 1] - a[i]) + abs(a[i - 1] - a[i + 1]);
		cout << res << ' ';
	}

	return 0;
}