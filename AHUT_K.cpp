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
const int N = 1e6 + 10;
int n, k;
int dist[N];

int solve(){
	memset(dist, -1, sizeof dist);
	cin >> n >> k;
	if(n == k) return 0;
	queue<int> q;
	q.push(n);
	dist[n] = 0;
	while(!q.empty()){
		int t = q.front();
		q.pop();
		if(t > 0 && dist[t - 1] == -1){
			dist[t - 1] = dist[t] + 1;
			q.push(t - 1);
		}
		if(t < N && dist[t + 1] == -1){
			dist[t + 1] = dist[t] + 1;
			q.push(t + 1);
		}
		if(t * 2 < N && dist[t * 2] == -1){
			dist[t * 2] = dist[t] + 1;
			q.push(t * 2);
		}
		if(dist[k] != -1) return dist[k];
	}
	return -1;
}


int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		cout << solve() << endl;
	}
	return 0;
}