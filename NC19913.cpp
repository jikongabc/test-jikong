#include<iostream>
#define int long long 
using namespace std;
signed main(){
    int n,b,i,temp,sum,ans=0;
    int a[100005],num[100005];
    cin>>n>>b;
    for(i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>b) a[i]=1;
        else if(a[i]<b) a[i]=-1;
        else temp=i;
    }
    for(i=temp-1;i>=0;i--){
        sum+=a[i];
        num[n+sum]++;
        if(!sum) ans++;
    }
    sum=0;
    for(i=temp+1;i<n;i++){
        sum+=a[i];
        ans+=num[n-sum];
        if(!sum) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
