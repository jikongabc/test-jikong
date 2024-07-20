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
const int N = 1e5 + 10;
int n;
int a[N];
int ans;
int res[N];
int tr[N];

int lowbit(int x){
    return x & -x;
}

void add(int x,int c){
    for (int i = x; i <= n;i+=lowbit(i))
        tr[i] += c;
}

int sum(int x){
    int res = 0;
    for (int i = x; i;i-=lowbit(i))
        res += tr[i];
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    int k = 0;
    ans = n;
    while(a[n-k]>a[n-k-1]){
        add(a[n - k], 1);
        ans--;
        k++;
    }
    add(a[n - k], 1);
    ans--;
    for (int i = 1; i <= n;i++){
        add(a[i], 1);
        res[i] = ans - i + sum(a[i] - 1);
    }
    cout << ans << endl;
    for (int i = 1; i <= ans;i++)
        cout << res[i] << ' ';
    return 0;
}
