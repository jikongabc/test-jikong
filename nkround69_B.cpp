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

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s;
	int n = s.size();
	LL a = 0;
	int i = 0;
	while(s[i] >= '0' && s[i] <= '9' && i < n){
		a = a * 10 + s[i] - '0';
		i++; 
	}
	while (i < s.size() && !isdigit(s[i])) {
        i++;
    }
    while(s[i] >= '0' && s[i] <= '9' && i < n){
		i++; 
	}
	while (i < s.size() && !isdigit(s[i])) {
        i++;
    }
	LL b = 0;
	string t = "";
	// i = n - 1;
	while(s[i] >= '0' && s[i] <= '9' && i < n){
		b = b * 10 + s[i] - '0';
		i++; 
	}
	// b = stoll(t);
	// cout << b << endl;
	cout << b - a - 1 - 1;
	return 0;
}