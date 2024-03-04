#include<iostream>
#define int long long
using namespace std;
signed main(){
    int n,m,i,sum=0,l=0,ans;
    int a[100005];
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        l=max(l,a[i]);
    }
    int r=sum;
    while(l<=r){
        int temp=0,num1=1;
        int mid=(l+r)/2;
        for(i=0;i<n;i++){
            if(temp+a[i]<=mid){
                temp+=a[i];
            }
            else{
                temp=a[i];
                num1++;
            }
        }
        if(num1<=m){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans;
    return 0;
}
