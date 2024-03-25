#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
const int N = 3e5 + 5;
int n, k;
int a[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    int ans = 0, r = 0;
    for (int i = 0, j = 0, zero = 0; i < n;i++){
        if(!a[i])
            zero++;
        while(zero>k && i>=j){
            if(!a[j])
                zero--;
            j++;
        }
        if(i-j+1>ans){
            ans = i - j + 1;
            r = i;
        }
    }
    cout << ans << endl;
    for (int i = 0; i <= r - ans;i++)
        cout << a[i] << ' ';
    for (int i = r - ans+1; i <=r;i++)
        cout << 1 << ' ';
    for (int i = r+1; i < n;i++)
        cout << a[i] << ' ';
        return 0;
}
