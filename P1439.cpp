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
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1e5 + 10;
int n;
int a[N], b[N];
int ma[N];
int q[N];


int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		cin >> b[i];
		ma[b[i]] = i;
	} 
	int len = 0;
	for(int i = 1; i <= n; i++){
		int l = 0, r = len;
		while(l < r){
			int mid = l + r + 1 >> 1;
			if(q[mid] < ma[a[i]]) l = mid;
			else r = mid - 1;
		}
		len = max(len, r + 1);
		q[r + 1] = ma[a[i]];
	}
	cout << len << endl;
	
	return 0;
}