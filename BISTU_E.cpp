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
const int N = 2020;
int n;
int a[N];
int b[N];

void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	reverse(b, b + n);
	vector<int> v;
	for(int i = n; i >= 1; i--){
		int pos = -1;
		for(int j = 0; j < n; j++){
			if(a[j] == i){
				pos = j;
				break;
			}
		}
		if(pos == i - 1) continue;
		if(pos != 0){
			v.push_back(pos + 1);
			for(int l = 0, r = pos; l < r; l++,r--){
				swap(a[l], a[r]);
			}
		}
		v.push_back(i);
		for(int l = 0, r = i - 1; l < r; l++, r--){
			swap(a[l], a[r]);
		}
	}
	cout << v.size() << endl;
	for(auto i : v){
		cout << i << ' ';
	}
	cout << endl;
}


int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}