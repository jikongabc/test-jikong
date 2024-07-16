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
const int N = 2e5 + 10;
string s;
int q;
int l1, r1, l2, r2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> q;
    while(q--){
        cin >> l1 >> r1 >> l2 >> r2;
        string s1 = s.substr(l1 - 1, r1 - l1 + 1);
        string s2 = s.substr(l2 - 1, r2 - l2 + 1);
        if(s1==s2)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}