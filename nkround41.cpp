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
const int N = 1e5 + 10;
char s[N];
int st[N];
int n, t;
int l, r;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    cin >> s + 1;
    while(t--){
        memset(st, 0, sizeof st);
        bool flag = 0;
        cin >> l >> r;
        map<char, int> ma;
        int cnt = 0;
        for (int i = l; i <= r;i++){
            ma[s[i]]++;
            for (int j = i + 1; j <= r;j++){
                if ( s[i]=='d' && s[j]=='r' || s[i]=='d' && s[j]=='e'){
                    st[j] = 1;
                    flag = 1;
                }
                else if (s[i] == 'e' && s[j] == 'r'){
                    st[j] = 2;
                    flag = 1;
                }
            }
        }
        for (int i = l; i <= r;i++){
            if(st[i])
                cnt+=st[i];
        }
        if (!flag && ma['r'] != 0 && ma['e'] != 0 && ma['d'] != 0)
        {
            cout << 0 << '\n';
        }
        else if(ma['r']!=0 && ma['e']!=0 && ma['d']==0 && !flag)
            cout << 1 << endl;
        else if(ma['e']!=0 && ma['d']!=0 && ma['r']==0 && !flag)
            cout << 1 << endl;
        else if(ma['d']!=0 && ma['r']!=0 && ma['e']==0 && !flag)
            cout << 1 << endl;
        else
            cout << cnt << '\n';
    }
    return 0;
}