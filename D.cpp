#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int n;
string s;

void solve(){
    if (!n % 2 || n == 2 && s[0] != s[1])
    {
        cout << "NO\n";
        return;
    }
    char ans[N];
    unordered_map<char, int> ma1;
    unordered_map<char, int> ma;
    for (int i = 0; i < n;i++){
        ma1[s[i]]++;
    }
    if(ma1['N']==1 && ma1['S']==1 && ma1['W']==1 && ma1['E']==1){
        cout << "HHRR\n";
        return;
    }
    if (ma1['N'] % 2 != 0 && ma1['S'] % 2 == 0 || ma1['N'] % 2 == 0 && ma1['S'] % 2 != 0)
    {
        cout << "NO\n";
        return;
    }
    if (ma1['E'] % 2 != 0 && (ma1['W'] % 2 == 0) || ma1['E'] % 2 == 0 && (ma1['W'] % 2 != 0))
    {
        cout << "NO" << endl;
        return;
    }
    

        for (int i = 0; i < n; i++)
        {
            ma[s[i]]++;
            if (ma[s[i]] == 1)
            {
                ans[i] = 'R';
            }
            if (ma[s[i]] == 2)
            {
                ans[i] = 'H';
                ma[s[i]] = 0;
            }
        }
        for (int i = 0; i < n;i++)
            cout << ans[i];
        cout << endl;
        return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        cin >> s;
        solve();
    }
    return 0;
}