#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 202020;
int a[N];
int p[N], q[N];
set<int> s1;
set<int> s2;
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        s1.insert(i);
        s2.insert(i);
    }
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (s1.find(a[i]) != s1.end())
            {
                p[i] = a[i];
                s1.erase(a[i]);
            }
            else if (s2.find(a[i]) != s2.end())
            {
                q[i] = a[i];
                s2.erase(a[i]);
            }
            else{
            cout << -1;
            return 0;
        }
    }
    int j = 1;
    for (int i = 1; i <= n;i++){
        if(!p[i]){
            p[i] = *s1.begin();
            s1.erase(*s1.begin());
        }
    }
    j = 1;
    for (int i = 1; i <= n;i++){
        if(!q[i]){
            q[i] = *s2.begin();
            s2.erase(*s2.begin());
        }
    }
    for (int i = 1; i <= n;i++){
        cout << p[i] << ' ';
    }
    cout << endl;
    for (int i = 1; i <= n;i++){
        cout << q[i] << ' ';
    }
        return 0;
}