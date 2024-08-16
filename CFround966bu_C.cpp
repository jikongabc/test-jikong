#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
int n, m;
int a[N];
string s;

void solve(){
    map<int, char> ma;
    map<char, int> ma1;
    cin >> s;
    bool flag = false;
    if(s.size()!=n){
        cout<<"NO\n";
        return;
    }
    for (int i = 0; i < n; i++){
        if (ma.count(a[i]) && ma[a[i]] != s[i] || ma1.count(s[i]) && ma1[s[i]]!=a[i]){
            cout << "NO\n";
            flag = true;
            return;
        }
        else{
            ma[a[i]] = s[i];
            ma1[s[i]] = a[i];
        }
            
    }
    if(!flag){
        cout << "YES\n";
        return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        cin >> m;
        while(m--){
            solve();
        }
    }
    return 0;
}
