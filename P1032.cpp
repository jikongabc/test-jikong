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
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 7;
string A, B;
string sa[N], sb[N];
int n;

int extend(queue<string> &q,unordered_map<string,int>&d1,unordered_map<string,int>&d2,string sa[],string sb[]){
    int d = d1[q.front()];
    while(!q.empty() && d==d1[q.front()]){
        string t = q.front();
        q.pop();
        for (int i = 0; i < t.size();i++){
            for (int j = 0; j < n; j++){
                if(t.substr(i,sa[j].size())==sa[j]){
                    string state = t.substr(0, i) + sb[j] + t.substr(i + sa[j].size());
                    if(d1.count(state))
                        continue;
                    if(d2.count(state)){
                        return d2[state] + 1 + d1[t];
                    }
                    q.push(state);
                    d1[state] = d1[t] + 1;
                }
            }
        }
    }
    return 11;
}

int bfs(){
    queue<string> q1, q2;
    unordered_map<string, int> d1, d2;
    q1.push(A), q2.push(B);
    d1[A] = 0, d2[B] = 0;
    int step = 0;
    while(q1.size() && q2.size()){
        int t;
        if(q1.size()<=q2.size())
            t = extend(q1, d1, d2, sa, sb);
        else
            t = extend(q2, d2, d1, sb, sa);
        if(t<=10)
            return t;
        if(++step==10)
            return -1;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B;
    if(A==B){
        cout << 0;
        return 0;
    }
    while(cin>>sa[n]>>sb[n])
        n++;
    int res = bfs();
    if(res==-1)
        cout << "NO ANSWER!";
    else
        cout << res;
    return 0;
}
