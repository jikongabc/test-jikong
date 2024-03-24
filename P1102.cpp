#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 2e5 + 5;
typedef long long LL;
int n, c;
int a[N];
LL ans = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> c;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0, j = 0, k = 0; i < n;i++){
        while(j<=i && a[i]-a[j]>=c){
            j++;
        }
        while(k<=i && a[i]-a[k]>c){
            k++;
        }
        ans += j - k;
    }
    cout << ans;
    return 0;
}