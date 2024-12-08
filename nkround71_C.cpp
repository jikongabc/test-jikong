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
string s;

bool pd(int x) {
    for (int shift = 0; shift < x; shift++) {
        bool flag = true;
        vector<char> a(x, '\0');
        for (int i = 0; i < s.size(); i++) {
            int j = (i + shift) % x;
            if (a[j] == '\0') {
                a[j] = s[i];
            } else {
                if (a[j] != s[i]) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    map<char, bool> ma;
    int t = 0;
    for (char c : s){
        if (!ma[c]){
            ma[c] = true;
            t++;
        }
    }
    cout << t;
    return 0;
}
