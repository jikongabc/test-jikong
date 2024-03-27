#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include<unordered_map>
#include<string>
using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
string s;
string end1 = "123804765";
unordered_map<string, int> dist;
unordered_map<string, int> vis;
queue<string> q;
int bfs(string s){
    dist[s] = 0;
    dist[end1] = 0;
    q.push(s);
    q.push(end1);
    vis[s] = 1, vis[end1] = 2;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        int distance = dist[t];
        int flag = vis[t];
        int x = t.find('0');
        for (int i = 0; i < 4;i++){
            int a = x / 3 + dx[i], b = x % 3 + dy[i];
            if(a<0 || a>=3 || b<0 || b>=3)
                continue;
            int temp = a * 3 + b;
            swap(t[x], t[temp]);
            if(vis[t]+flag==3){
                int res1 = dist[t];
                swap(t[x], t[temp]);
                int res2 = dist[t];
                return res1 + res2 + 1;
            }
            if(!dist.count(t)){
                dist[t] = distance + 1;
                vis[t] = flag;
                q.push(t);
            }
            swap(t[x], t[temp]);
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    if(s==end1)
        cout << 0;
    else{
        int ans = bfs(s);
        cout << ans;
    }
    return 0;
}