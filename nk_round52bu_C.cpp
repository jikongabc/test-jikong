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
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1e5 + 10;
int n, cnt1, cnt2;
int a[N];
map<int,int> ma;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        if(a[i]>=0)
            ma[a[i]]++;
        else
            cnt1++;
    }
    for(auto i:ma){
        cnt2 += i.second % 2;
    }
    // cout << cnt1 << ' ' << cnt2 << endl;
    if(cnt1>cnt2)
        cout << (cnt1 - cnt2) % 2 << endl;
    else
        cout << cnt2 - cnt1;
    return 0;
}