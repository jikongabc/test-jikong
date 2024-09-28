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
const int N = 2e6 + 10;
int n, m;
unordered_map<string,int> id;
int d[N];
int fa[N];

int find(int x){
	if(fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string s1, s2;
	for(int i = 1; i <= N ; i++) fa[i] = i;
	while(cin >> s1 >> s2){
		if(!id[s1]) id[s1] = ++n;
		if(!id[s2]) id[s2] = ++n;
		m++;
		d[id[s1]]++, d[id[s2]]++;
		int a = find(id[s1]), b = find(id[s2]);
		fa[a] = b;
 	}
 	int start = 0, end1 = 0;
 	bool flag = true;
 	int cnt = 0;
 	for(int i = 1;i <= n; i++){
 		if(d[i] & 1) cnt++;
 	}
 	if(cnt !=0 && cnt != 2) flag = false;
 	int rep = -1;
 	for(int i = 1; i <= n; i++){
 		if(d[i]){
 			if(rep == -1) rep = find(i);
 			else if(rep != find(i)){
 				flag = false;
 				break;
 			}
 		}
 	}
 	if(flag) cout << "Possible";
 	else cout << "Impossible";
	return 0;
}