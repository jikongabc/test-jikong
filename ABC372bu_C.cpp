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
#include <bitset>
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 2e5 + 10;
int n, q;
string s;
int res;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    cin >> s;
    for (int i = 0; i <= n - 3;i++){
        if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C')
            res++;
    }
    // cout << res << endl;
    while (q--)
    {
        int x;
        char c;
        cin >> x >> c;
        x--;
        for (int i = 0; i < 3;i++){
            int t = x - i;
            if(t>=0 && t+2<n){
                if(s[t]=='A' && s[t+1]=='B' && s[t+2]=='C')
                    res--;
            }
        }
        s[x] = c;
        for (int i = 0; i < 3;i++){
            int t = x - i;
            if(t>=0 && t+2<n){
                if(s[t]=='A' && s[t+1]=='B' && s[t+2]=='C')
                    res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}