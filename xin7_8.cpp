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
string s;
int cnt[1000];

int main(){
	// ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s;
	int n = s.size();
	for(int i = 0; i < n; i++){
		// cout <<(int)s[i] << ' ';
		cnt[s[i]]++;
		// cout << cnt[s[i]] << ' ';
	}
	bool flag = false;
	for(int i = 'A'; i <= 'Z'; i++){n
		// cout << cnt[i] << ' ';
		if(cnt[i] >= 3){
			cout << "\"" << (char)i << "\"" << endl; 
			flag = true;
		}
	}
	for(int i = 'a'; i <= 'z'; i++){
		// cout << cnt[i] << ' ';
		if(cnt[i] >= 3){
			cout << "\"" << (char)i << "\"" << endl; 
			flag = true;
		}
	}
	if(!flag) cout << "\"quiet class\"" << endl;

	return 0;
}