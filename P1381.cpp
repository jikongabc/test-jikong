#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 2005, M = 2e5 + 10;
int n, m;
map<string, int> ma;
int t;
int a[M];
int b[M];
int res;
bool st[N];
int sst[N];

bool check(int x){
    memset(sst, 0, sizeof sst);
    int sum = 0;
    int ans = 0;
    for (int i = 1; i <= x;i++){
        if(a[i]<=n && sst[a[i]]==0)
            sum++;
        sst[a[i]]++;
    }
    for (int i = 1, j = x; i <= m - x + 1;i++,j++){
        ans = max(ans, sum);
        sum -= ((a[i] <= n) && sst[a[i]] == 1);
        sst[a[i]]--;
        sum += (((a[j+1] <= n) && !sst[a[j+1]]));
        sst[a[j+1]]++;
    }
    if(ans==res)
        return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        string s;
        cin >> s;
        ma[s] = ++t;
    }
    //需要记住的单词:1-n
    cin >> m;
    for (int i = 1; i <= m;i++){
        string s;
        cin >> s;
        if(ma.count(s)==0)
            ma[s] = ++t;
        else{
            if(!st[ma[s]] && (ma[s]<=n))
                res++;
            st[ma[s]] = 1;
        }
        a[i] = ma[s];
    }
    int l = res, r = m;
    while(l<r){
        int mid = l + r >> 1;
        if(check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << res << endl;
    cout << r << endl;
    return 0;
}