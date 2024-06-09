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
const int N = 5005;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    if(a==b)
        cout << "p";
    else if(a==1 && b==2 || a==2 && b==3 || a==3 && b==1)
        cout << "a";
    else
        cout << "b";
    return 0;
}