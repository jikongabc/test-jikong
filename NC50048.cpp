#include<iostream>
#define int long long
using namespace std;
signed main(){
    int n,i,ans,temp;
    cin>>n;
    int a[100005],b[100005],c[100005]={0};
    for(i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<=n;i++){
        cin>>b[i];
        c[i]=c[i-1]+b[i];
    } 
    for(i=1;i<=n;i++){
        int l=i,r=n;
        while(l<=r){
            temp=a[i];
            int mid=(l+r)/2;
            temp-=(c[mid]-c[i-1]);
            if(temp<=0){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            } 
        }
        if(a[i]-(c[n]-c[i-1])<=0) cout<<ans<<' ';
        else cout<<n+1<<' ';
    }
    cout<<endl;
    return 0;
}
