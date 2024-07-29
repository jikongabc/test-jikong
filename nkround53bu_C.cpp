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
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1e5 + 10;
int n;
string s;
int x, y, z;

void solve(){
    int cnt = 0;
    int res = 0;
    for (int i = 0; i < n;i++){
        if(s[i]=='0')
            cnt++;
        else if (s[i] == '1' && cnt>0){
            cnt--;
            res++;
        }
    }
    cout << min(res, y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> s;
    cin >> x >> y >> z;
    solve();
    return 0;
}