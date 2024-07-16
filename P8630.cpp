#include <iostream>
#include <algorithm>
#include <cstring>
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
const int N = 1200000, M = 1005;
string s;
int n;
int res;
map<string, int> ma;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    cin >> n;
    for (int i = 0; i < n;i++){
        string x;
        cin >> x;
        sort(x.begin(), x.end());
        ma[x]++;
    }
    for (int i = 0; i <= s.size() - 8;i++){
        string ss = s.substr(i, 8);
        sort(ss.begin(), ss.end());
        res += ma[ss];
    }
    cout << res;
    return 0;
}