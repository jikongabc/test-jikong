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
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, string> PIS;
typedef pair<char, string> PCS;
const int N = 1e5 + 10;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
string end1 = "123x46758";
string op = "urdl";
string start;

int f(string state){
    int res = 0;
    for (int i = 0; i < 9;i++){
        if(state[i]!='x'){
            int t = state[i] - '1';
            res += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
        }
    }
    return res;
}

string astar(){
    priority_queue<PIS, vector<PIS>, greater<PIS>> q;
    unordered_map<string, int> dist;
    unordered_map<string, PCS> pre;
    q.push({f(start), start});
    dist[start] = 0;
    int x, y;
    while(!q.empty()){
        auto [dis, state] = q.top();
        q.pop();
        if(state==end1)
            break;
        for (int i = 0; i < 9;i++){
            if(state[i]=='x'){
                x = i / 3, y = i % 3;
                break;
            }
        }
        string tmp = state;
        for (int i = 0; i < 4;i++){
            state = tmp;
            int a = x + dx[i], b = y + dy[i];
            if(a<0 || a>=3 || b<0 ||b>=3)
                continue;
            swap(state[a * 3 + b], state[x * 3 + y]);
            if(!dist.count(state) || dist[state]>dist[tmp]+1){
                dist[state] = dist[tmp] + 1;
                pre[state] = {op[i], tmp};
                q.push({f(state) + dist[state], state});
            }
        }
    }
    string res;
    while(end1!=start){
        res += pre[end1].first;
        end1 = pre[end1].second;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    for (int i = 0; i < 9;i++){
        char c;
        cin >> c;
        start += c;
        if(c!='x')
            s += c;
    }
    int cnt = 0;
    for (int i = 0; i < 7;i++){
        for (int j = i + 1; j < 8;j++){
            if(s[i]>s[j])
                cnt++;
        }
    }
    if(cnt&1)
        cout << "unsolvable";
    else
        cout << astar();
    return 0;
}
