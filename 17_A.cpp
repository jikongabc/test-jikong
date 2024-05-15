#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
double a[N];
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    sort(a, a + n);
    printf("%.1lf", (a[0]+a[n-1])/2);
    return 0;
}
