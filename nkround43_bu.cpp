#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N = 1e5 + 10;
int n;
int a[N], b[N];
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    s = " " + s;
    n = s.size();
    for (int i = 1; i <= n;i++){
        if(s[i]>='a' && s[i]<='z')
            a[i] = a[i - 1] + 1;
        else
            a[i] = a[i - 1];
    }
    for (int i = n; i >= 1;i--){
        if(s[i]>='A' && s[i]<='Z')
            b[i] = b[i + 1] + 1;
        else
            b[i] = b[i + 1];
    }
    int ans = inf;
    for (int i = 1; i < n-1;i++){
        ans = min(ans, a[i] + b[i + 1]);
    }
    cout << ans;
    return 0;
}
