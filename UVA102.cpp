
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
LL a[3][3];
// BGC
string s[6] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
LL res[6];
LL ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> a[0][0] >> a[0][1] >> a[0][2] >> a[1][0] >> a[1][1] >> a[1][2] >> a[2][0] >> a[2][1] >> a[2][2]){
        // cin >> a[0][0] >> a[0][1] >> a[0][2] >> a[1][0] >> a[1][1] >> a[1][2] >> a[2][0] >> a[2][1] >> a[2][2];
        res[0] = a[1][0] + a[2][0] + a[0][2] + a[2][2] + a[0][1] + a[1][1];
        res[1] = a[1][0] + a[2][0] + a[0][1] + a[2][1] + a[0][2] + a[1][2];
        res[2] = a[1][2] + a[2][2] + a[0][0] + a[2][0] + a[0][1] + a[1][1];
        res[3] = a[1][2] + a[2][2] + a[0][1] + a[2][1] + a[0][0] + a[1][0];
        res[4] = a[1][1] + a[2][1] + a[0][0] + a[2][0] + a[0][2] + a[1][2];
        res[5] = a[1][1] + a[2][1] + a[0][2] + a[2][2] + a[0][0] + a[1][0];
        ans = res[0];
        LL temp = 0;
        for (int i = 1; i < 6; i++){
            if (res[i] < ans){
                ans = res[i];
                temp = i;
            }
        }
        cout << s[temp] << ' ' << res[temp] << endl;
    }
        return 0;
}


