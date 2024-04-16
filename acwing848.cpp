#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 2e5 + 10;
int n, m;
int d[N];
int h[N], e[N], ne[N], idx;
queue<int> q;
queue<int> q1;

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort(){
    int cnt = -1;
    for (int i = 1; i <= n;i++){
        if(!d[i]){
            q.push(i);
            cnt++;
        }
    }
    while(!q.empty()){
        int t = q.front();
        q1.push(t);
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(--d[j]==0){
                q.push(j);
                cnt++;
            }
        }
    }
    return cnt == n - 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m;i++){
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }
    if(!topsort()) cout<<-1;
    else{
        while(!q1.empty()){
            cout << q1.front() << ' ';
            q1.pop();
        }
    }
    return 0;
}