#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<double, int> PDI; 
const int N = 1e5 + 10;
char g[2][4];
string start = "12345678", end1;
unordered_map<string, pair<char, string>> pre;
unordered_map<string, int> dist;
queue<string> q;

void _set(string state){
    for (int i = 0; i < 4;i++)
        g[0][i] = state[i];
    for (int i = 7, j = 0; j < 4;i--,j++)
        g[1][j] = state[i];
}

string _get(){
    string res;
    for (int i = 0; i < 4;i++)
        res += g[0][i];
    for (int i = 3; i >= 0;i--)
        res += g[1][i];
    return res;
}

string move0(string state){
    _set(state);
    for (int i = 0; i < 4;i++)
        swap(g[0][i], g[1][i]);
    return _get();
}

string move1(string state){
    _set(state);
    int v0 = g[0][3], v1 = g[1][3];
    for (int i = 3; i > 0;i--){
        g[0][i] = g[0][i - 1];
        g[1][i] = g[1][i - 1];
    }
    g[0][0] = v0, g[1][0] = v1;
    return _get();
}

string move2(string state){
    _set(state);
    int temp = g[0][1];
    g[0][1] = g[1][1];
    g[1][1] = g[1][2];
    g[1][2] = g[0][2];
    g[0][2] = temp;
    return _get();
}

int bfs(){
    if(start==end1)
        return 0;
    q.push(start);
    dist[start] = 0;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        string m[3];
        m[0] = move0(t);
        m[1] = move1(t);
        m[2] = move2(t);
        for (int i = 0; i < 3;i++){
            if(!dist.count(m[i])){
                dist[m[i]] = dist[t] + 1;
                pre[m[i]] = {'A' + i, t};
                if(m[i]==end1)
                    return dist[end1];
                q.push(m[i]);
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 8;i++){
        int num;
        cin >> num;
        end1 += (char)(num + '0');
    }
    int ans = bfs();
    cout << ans << endl;
    string res;
    while(end1!=start){
        res += pre[end1].first;
        end1 = pre[end1].second;
    }
    reverse(res.begin(), res.end());
    if(ans>0)
        cout << res << endl;
    return 0;
}