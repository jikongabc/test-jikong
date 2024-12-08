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
#include <climits>
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
#define lnf LLONG_MAX
#define endl '\n'
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const double pi = acos(-1);
const int N = 1e5 + 10; 

int n;
string s;

void solve(){
    cin >> n >> s;
    bool flag = false;
    vector<int> pos[26];
    for (int i = 0; i < n; i++){
        pos[s[i] - 'a'].push_back(i);
        if (s[i] == s[(i + 1) % n]){
            flag = true;
        }
    }
    if (flag){
        cout << 0 << endl;
        return;
    }
    int minn = inf;
    for (int i = 0; i < 26; i++){
        if (pos[i].size() < 2) continue;
        int k = pos[i].size();
        for (int j = 0; j < k; j++){
            int t = pos[i][j];
            int next = pos[i][(j + 1) % k];
            int d;
            if (next > t) d = next - t - 1;
            else d = n - t + next - 1;
            minn = min(minn, d);
        }
    }
    if (minn <= n - 2) cout << minn << endl;
    else cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
