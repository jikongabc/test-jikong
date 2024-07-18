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
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
int n, k;
ULL m;
priority_queue < ULL, vector<ULL>, greater<ULL>> q;
ULL res;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n;i++){
        ULL x;
        cin >> x;
        q.push(x);
    }
    while(q.size() ){
        if(m-q.top()<=0)
            break;
        m -= q.top();
        q.pop();
        res++;
    }
    if(res+k>=n)
        res = n;
    else
        res += k;
    cout << res;
    return 0;
}