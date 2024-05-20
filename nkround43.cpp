#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cmath>
#include<unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e5+10;
int n;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    n = s.size();
    int cnt = 0;
    int cnt1 = 0;
    bool pd1 = 0, pd2 = 0;
    int ans1 = 0, ans2 = 0;
    for (int i = 0;i<n;i++){
        if(s[i]>='a' && s[i]<='z')
            pd1 = 1;
        if(s[i]>='A' && s[i]<='Z')
            pd2 = 1;
        if(s[i]>='a' && s[i]<='z')
            cnt1++;
        if (s[i] >= 'a' && s[i] <= 'z' && s[i + 1] >= 'A' && s[i + 1] <= 'Z'){
            ans1 += cnt1;
            cnt1 = 0;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            cnt++;
        if (s[i] >= 'A' && s[i] <= 'Z' && s[i - 1] >= 'a' && s[i - 1] <= 'z'){
            ans2 += cnt;
            cnt = 0;
        }
    }
    if (s[0] >= 'a' && s[0] <= 'z')
        ans2++;
    if(s[n-1]>='A' && s[n-1] <='Z')
        ans1++;
    if(!pd1 || !pd2){
        cout << 1;
        return 0;
    }
    cout << ans1 << ' ' << ans2 << endl;
    cout << min(ans1, ans2);
    return 0;
}