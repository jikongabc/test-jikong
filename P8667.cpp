#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1e5 + 5;
typedef long long LL;
int n;
int a[N], b[N], c[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= n;i++)
        cin >> b[i];
    for (int i = 1; i <= n;i++)
        cin >> c[i];
    sort(a+1, a + n+1);
    sort(b+1, b + n+1);
    sort(c+1, c + n+1);
    LL ans = 0;
    for (int i = 1, IndexA = 1, IndexC = 1; i <= n;i++){
        int B = b[i];
        while(IndexA <=n && a[IndexA]<B){
            IndexA++;
        }
        while(IndexC <=n && c[IndexC]<=B){
            IndexC++;
        }
        ans += (LL)(IndexA -1) * (n - IndexC + 1);
    }
    cout << ans;
    return 0;
}