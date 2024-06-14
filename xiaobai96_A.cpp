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
using namespace std;
using LL = long long;
typedef pair<int, int> PII;
string s1, s2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s1 >> s2;
    set<char> ss1;
    set<char> ss2;
    for (int i = 0; i < s1.size();i++){
        ss1.insert(s1[i]);
    }
    for (int i = 0; i < s2.size();i++){
        ss2.insert(s2[i]);
    }
    int minn = min(ss1.size(), ss2.size());
    int maxn = max(ss1.size(), ss2.size());
    if(maxn==6){
        cout << -1;
        return 0;
    }
    cout << maxn - minn + 1;
    return 0;
}