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
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1e5 + 10;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    bool flag = false;
    while(n--){
        cin >> s;
        if(s=="sweet" && !flag)
            flag = 1;
        else if(s=="sweet" && flag && n>0){
            cout << "No";
            return 0;
        }
        else if (s == "salty")
            flag = 0;
    }
    cout << "Yes";
    return 0;
}