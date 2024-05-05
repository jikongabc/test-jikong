#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
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
typedef pair<double, int> PDI;
const int N = 1005;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
bool st[N];
int n;
char s[N];
map<char, int> ma;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> s+1;
    int ans = 0;
    for (int i = 1; i <= n;i++){
        ma[s[i]]++;
    }
    if (ma['b'] == 0 || ma['r'] == 0){
        cout << n;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        memset(st, false, sizeof st);
        int l = i, r = i + (i == n ? -n + 1 : 1);
        char ch_l = s[l], ch_r = s[r];
        int cnt1 = 0, cnt2 = 0;
        while (ch_l == 'w')
        {
            l -= (l == 1 ? -n + 1 : 1);
            ch_l = s[l];
        }
        while (ch_r == 'w')
        {
            r += (r == n ? -n + 1 : 1);
            ch_r = s[r];
        }
        l = i, r = i + (i == n ? -n + 1 : 1);
        if (ch_l != ch_r)
        {
            while (s[l] == ch_l || s[l] == 'w')
            {
                l -= (l == 1 ? -n + 1 : 1);
                if(s[l]=='w')
                    st[l] = 1;
                cnt1++;
            }
            while (s[r] == ch_r || s[r] == 'w')
            {
                r += (r == n ? -n + 1 : 1);
                if(!st[r])
                    cnt2++;
            }
            ans = max(ans, cnt1 + cnt2);
        }
    }
    cout << ans;
    return 0;
}