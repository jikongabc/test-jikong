#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int g[2][4];
unordered_map<string, int> dist;
unordered_map<string,pair<char,string> > pre;
queue<string> q;

void set1(string state){
    for (int i = 0; i < 4;i++){
        g[0][i] = state[i];
    }
    for (int i = 3, j = 4; i >= 0;i--,j++){
        g[1][i] = state[j];
    }
}

string get1(){
    string res;
    for (int i = 0; i < 4;i++){
        res += g[0][i];
    }
    for (int i = 3; i >= 0;i--){
        res += g[1][i];
    }
    return res;
}

string move0(string state){
    set1(state);
    for (int i = 0; i < 4;i++){
        swap(g[0][i], g[1][i]);
    }
    return get1();
}

string move1(string state){
    set1(state);
    char v0 = g[0][3], v1 = g[1][3];
    for (int i = 3; i > 0;i--){
        for (int j = 0; j < 2;j++){
            g[j][i] = g[j][i - 1];
        }
    }
    g[0][0] = v0, g[1][0] = v1;
    return get1();
}

string move2(string state){
    set1(state);
    char temp = g[0][1];
    g[0][1] = g[1][1];
    g[1][1] = g[1][2];
    g[1][2] = g[0][2];
    g[0][2] = temp;
    return get1();
}

int bfs(string start,string end1){
    q.push(start);
    dist[start] = 0;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        if(t==end1)
            return dist[end1];
        string m[3];
        m[0] = move0(t);
        m[1] = move1(t);
        m[2] = move2(t);
        for (int i = 0; i < 3;i++){
            string s = m[i];
            if(!dist.count(s)){
                dist[s] = dist[t] + 1;
                pre[s] = {char(i + 'A'), t};
                if(s==end1)
                    return dist[end1];
                q.push(s);
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x;
    string start, end1;
    // cout << start << end1;
    for (int i = 1; i <= 8;i++){
        cin >> x;
        end1 += char(x + '0');
    }
    for (int i = 1; i <= 8; i++){
        start += char(i + '0');
    }
    int res = bfs(start, end1);
    cout << res << endl;
    string res2;
    while (end1 != start){
        res2 += pre[end1].first;
        end1 = pre[end1].second;
    }
    reverse(res2.begin(), res2.end());
    if(res2.size()){
        cout << res2 << endl;
    }
    return 0;
}
