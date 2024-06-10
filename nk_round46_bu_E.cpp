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
const int N = 1e5 + 10;
int n, q;
LL pre[N], suf[N];

struct node{
    int a, b;
} p[N];

bool cmp(node a,node b){
    return a.b < b.b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> p[i].a;
    }
    for (int i = 1; i <= n;i++){
        cin >> p[i].b;
    }
    sort(p + 1, p + 1 + n, cmp);
    for (int i = 1; i <= n;i++){
        pre[i] = pre[i - 1] + p[i].a * p[i].b;
    }
    for (int i = n; i >= 1;i--){
        suf[i] = suf[i + 1] + p[i].a;
    }
    cin >> q;
    while(q--){
        LL k;
        cin >> k;
        LL l = 0, r = n;
        LL res;
        while(l<=r){
            int mid = (l + r) >> 1;
            if(p[mid].b<k){
                l = mid + 1;
                res = mid;
            } 
            else{
                r = mid - 1;
            }
        }
        cout << pre[res] + suf[res + 1] * k << endl;
    }
    return 0;
}