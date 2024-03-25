#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
using LL = long long;
const int N = 50005;
int n, k;
int a[N],cnt_lr[N],cnt_rl[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    for (int i = 0, j = 0; i < n;i++){
        while(j<=i && a[i]-a[j]>k){
            j++;
        }
        cnt_lr[i] = max(cnt_lr[i-1], i - j + 1);
    }
    for (int i = n - 1, j = n - 1; i >= 0;i--){
        while(j>=i && a[j]-a[i]>k){
            j--;
        }
        cnt_rl[i] = max(cnt_rl[i + 1], j - i + 1);
    }
    for (int i = 0; i < n-1;i++){
        ans = max(ans, cnt_lr[i] + cnt_rl[i + 1]);
    }
    cout << ans;
    return 0;
}
