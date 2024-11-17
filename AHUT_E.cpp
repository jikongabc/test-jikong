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
const int N = 1e5 + 10;
int n;
vector<int> v1, v2;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	LL res = 0, sum = 0;
	for(int i = 0; i < n;i++){
		int x;
		cin >> x;
		if(x % 2 == 1) v1.push_back(x);
		else v2.push_back(x);
		sum += x;
	}
	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	if(v1.size() > v2.size()){
		while(v2.size()){
			res += v1.back();
			v1.pop_back();
			res += v2.back();
			v2.pop_back();
		}
		res += v1.back();
	}
	else if(v1.size() == v2.size()){
		while(v2.size()){
			res += v1.back();
			v1.pop_back();
			res += v2.back();
			v2.pop_back();
		}
	}
	else{
		while(v1.size()){
			res += v1.back();
			v1.pop_back();
			res += v2.back();
			v2.pop_back();
		}
		res += v2.back();
	}
	cout << sum - res;
	return 0;
}