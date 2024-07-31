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
typedef pair<int, PII> PIII;
const int N = 1e5 + 10;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n;i++){
        string s;
        cin >> s;
        s += '.';
        int tmp = 0;
        priority_queue<int> q;
        for (int i = 0; i < s.size();i++){
            if(s[i]!='.'){
                tmp *= 10;
                tmp += s[i] - '0';
            }
            else{
                // cout << tmp << ' ';
                q.emplace(tmp);
                tmp = 0;
            }   
        }
        if (q.top() > 255)
            continue;
        else
            res++;
        // cout << endl;
    }
    cout << res;
    return 0;
}