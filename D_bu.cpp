#include<bits/stdc++.h>
using namespace std;
const string t = "EWNS";
int n;
string s;
int w[1000];

void solve(){
    w['N'] = w['S'] = 0;
    w['E'] = w['W'] = 1;
    string ans = "";
    bool flag1 = false, flag2 = false;
    for (int i = 0; i < n;i++){
        ans += (w[s[i]] == 0) ? 'H' : 'R';
        if(ans[i]=='H')
            flag1 = 1;
        if(ans[i]=='R')
            flag2 = 1;
        w[s[i]] ^= 1;
    }
    if (flag1 && flag2 && w['N'] == w['S'] && w['E'] == w['W'])
        cout << ans << endl;
    else
        cout << "NO\n";
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