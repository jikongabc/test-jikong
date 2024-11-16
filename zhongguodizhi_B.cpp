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
const int N = 101010;
int n, m;
int stk[N], top;
int a[N], b[N];
priority_queue <PII, vector<PII>, greater<PII>> q;

struct Node{
	int id, date, iid; 
};

bool cmp(Node a, Node b){
	if(a.date == b.date) return a.iid > b.iid;
	return a.date > b.date;
}

vector<Node> v;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		stk[++top] = i;
	}
	int cnt = 0;
	while(m--){
		int t, id, d;
		string s;
		cin >> t >> s >> id;
		Node tq;
		if(!v.empty()){
			tq = *(v.end() - 1);
		}
		while(t >= tq.date && v.size() >= 1){
			// tq = *(v.end() - 1);
			v.pop_back();
			if(top && !a[tq.id]){
				a[tq.id] = stk[top--];
			}
			b[tq.id] = 0;
			tq = *(v.end() - 1);
			// sort(v.begin(), v.end(), cmp);
		}
		if(s == "RESERVE"){
			cin >> d;
			if(!a[id] && !b[id]){
				cout << 1  << endl;
				// q.push({t + d, id});
				v.push_back({id, t + d, cnt++});
				// cout << ' ' << cnt << endl; 
				sort(v.begin(), v.end(), cmp);
				b[id] = t + d;
			} 
			else cout << 0 << endl;
		}
		else if(s == "BORROW"){
			// cout <<"top:"<< top << ' ';
			// cout << "A:" << a[id] << ' ' << "B:" << b[id] << ' ';
			// cout << top << ' ';
			if(top && !a[id] && !b[id]){
				cout << stk[top] << endl;
				a[id] = stk[top--];
				// cout << ' ' << a[id] << endl;
			}
			else cout << 0 << endl;
		}
		else if(s == "RETURN"){
			if(!a[id]) cout << 0 << endl;
			else{
				cout << a[id] << endl;
				stk[++top] = a[id];
				a[id] = 0;
			}
		}
		else{
			if(!a[id]) cout << 0 << endl;
			else cout << a[id] << endl;
		}

	}
	return 0;
}