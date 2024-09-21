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
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1e6 + 10;
int n;
string s;
char stk[N];
int top;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> s;
    for (int i = 0; i < n;i++){
        if(top>0 && (stk[top]=='f' && s[i]=='c' || stk[top]=='t' && s[i]=='b'))
            top--;
        else
            stk[++top] = s[i];
    }
    cout << top;
    return 0;
}