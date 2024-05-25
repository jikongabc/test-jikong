#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
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
typedef pair<PII, int> PIII;
string s;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> s;
        n = s.size();
        int cnt = 0;
        int res = 0;
        for (int i = 0; i < n - 1;i++){
            if(s[i]=='0' && s[i+1]=='1')
                cnt++;
            if(s[i]!=s[i+1])
                res++;
        }
        if(cnt>0)
            res--;
        cout << res + 1 << endl;
    }
    return 0;
}