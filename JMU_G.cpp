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
const int N = 105;
int n;
PII a[N];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second;
	}
	for(int i = 0; i < n - 2; i++){
		for(int j = i + 1; j < n - 1; j++){
			if(a[j].second == a[i].second && a[j].first == a[i].first) continue;
			for(int k = j + 1; k < n; k++){
				if(a[k].second == a[j].second && a[k].first == a[j].first || a[k].second == a[i].second && a[k].first == a[i].first) continue;
				if(a[k].first - a[j].first == 0 && a[k].first - a[i].first == 0){
					cout << "Yes";
					return 0;
				}
				double k1 = (a[k].second - a[j].second) * 1.0 / (a[k].first - a[j].first);
				double k2 = (a[k].second - a[i].second) * 1.0 / (a[k].first - a[i].first);
				if(k1 == k2){
					// cout << "---" << i << ' ' << j << ' ' << k;
					cout << "Yes";
					return 0;
				}
			}
		}
	}
	cout << "No";
	return 0;
}