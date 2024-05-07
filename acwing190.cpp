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
const int N = 7;
string A, B;
string a[N], b[N];
unordered_map<string, int> dist_a, dist_b;
queue<string> q1, q2;
int n;

int extend(queue<string>& q,unordered_map<string,int>& dist1,unordered_map<string,int>& dist2,string a[],string b[]){
    string t = q.front();
    q.pop();
    for (int i = 0; i < t.size();i++){
        for (int j = 0; j < n;j++){
            if(t.substr(i,a[j].size())==a[j]){
                string new_t = t.substr(0, i) + b[j] + t.substr(i + a[j].size());
                if(dist2.count(new_t))
                    return dist1[t] + 1 + dist2[new_t];
                if(dist1.count(new_t))
                    continue;
                q.push(new_t);
                dist1[new_t] = dist1[t] + 1;
            }
        }
    }
    return 11;
}

int bfs(string A,string B){
    if(A==B)
        return 0;
    int t;
    dist_a[A] = 0, dist_b[B] = 0;
    q1.push(A), q2.push(B);
    while(!q1.empty() && !q2.empty()){
        if(q1.size()<=q2.size())
            t = extend(q1, dist_a, dist_b, a, b);
        else
            t = extend(q2, dist_b, dist_a, b, a);
        if(t<=10)
            return t;
    }
    return 11;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B;
    while(cin>>a[n]>>b[n])
        n++;
    int t = bfs(A, B);
    if(t>10)
        cout << "NO ANSWER!";
    else
        cout << t;
    return 0;
}