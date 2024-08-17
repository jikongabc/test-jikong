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
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int i = n - 1;
    while(s[i]=='0' || s[i]=='.')
        i--;
    for (int j = 0; j <= i;j++)
        cout << s[j];
    if(i==-1)
        cout << 0 << endl;
        return 0;
}
