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
#include <stack>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1e6 + 10;
int n;
string s;
// string s1 = "fc";
// string s2 = "tb";
stack<char> stk;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> s;

    for (char ch : s)
    {
        if (!stk.empty() && ((stk.top() == 'f' && ch == 'c') || (stk.top() == 't' && ch == 'b')))
        {
            stk.pop(); 
        }
        else
        {
            stk.push(ch); 
        }
    }

    cout << stk.size() << endl;
    return 0;
}