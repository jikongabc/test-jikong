#include <iostream>
#include <sstream>
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
const int N = 1e5 + 10;
int n, q;
int k;

struct node{
    int a, b;
} p[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    LL sum = 0;
    for (int i = 1; i <= n;i++){
        cin >> p[i].a;
    }
    for (int i = 1; i <= n;i++){
        cin >> p[i].b;
        sum += p[i].b;
    }
    cin >> q;
    int cnt = 0;
    int res[N];
    while(sum>=1){
        LL ssum = 0;
        LL sssum = 0;
        cnt++;
        for (int i = 1; i <= n;i++){
            if(p[i].b>0){
                p[i].b--;
                ssum += p[i].a;
                sssum++;
            }
        }
        res[cnt] = res[cnt - 1] + ssum;
        sum -= sssum;
    }
    while(q--){
        cin >> k;
        if(k>cnt)
            cout << res[cnt] << endl;
        else
            cout << res[k] << endl;
    }
    return 0;
}
