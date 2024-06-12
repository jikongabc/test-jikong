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
string a, b;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> a >> b;
        cout << b[0] << a[1] << a[2] << ' ' << a[0] << b[1] << b[2] << endl;
    }
    return 0;
}