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
using namespace std;
using LL = long long;
typedef pair<int, int> PII;
int n, m;
string s;
string ss = "ABCDEFG";
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        cin >> s;
        map<char, int> ma;
        for (int i = 0; i < n;i++){
            ma[s[i]]++;
        }
        int res = 0;
        for (int i = 0; i < 7;i++){
            if(ma[ss[i]]<m)
                res += m - ma[ss[i]];
        }
        cout << res << endl;
    }
    return 0;
}