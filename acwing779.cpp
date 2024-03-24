#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100005], cnt[100005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,ans=0;
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    for (int i = 0, j = 0; i < n;i++){
        cnt[a[i]]++;
        while(cnt[a[i]]>1){
            cnt[a[j]]--;
            j++;
        }
        ans = max(ans, i-j+1);
    }
    cout << ans;
    return 0;
}