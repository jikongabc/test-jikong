#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        bool flag = false;
        cin >> s;
        int n = s.size();
        int t = s[0] - '0';
        for (int i = 1; i < n;i++) {
            if (s[i] - '0' <= t)
                t = s[i] - '0';
            else{
                cout << "YES\n";
                flag = true;
                break;
            }
        }
        if(!flag)
            cout << "NO\n";
    }
    return 0;
}