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
#define endl '\n'
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
// const int N =  ;

LL gcd(LL a, LL b) {
    a = abs(a);
    b = abs(b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

LL gcd3(LL a, LL b, LL c) {
    return gcd(gcd(a, b), c);
}

void solve(LL& x, LL& y, LL& z) {
    LL g = gcd3(x, y, z);
    if (g > 0) {
        x /= g;
        y /= g;
        z /= g;
    }
    // 确保z为正
    if (z < 0) {
        x = -x;
        y = -y;
        z = -z;
    }
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    LL h;
    cin >> n >> h;
    
    for (int i = 0; i < n; i++) {
        LL x, y, z;
        cin >> x >> y >> z;
        LL vx = x;
        LL vy = y;
        LL vz = 2 * h - z;
        solve(vx, vy, vz);
        
        cout << vx << " " << vy << " " << vz << endl;
    }
    
    return 0;
}