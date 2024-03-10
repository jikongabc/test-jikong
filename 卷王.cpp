#include<iostream>
#include<algorithm>
#define int long long
int a[200005],b[200005];
using namespace std;
signed main(){
    int n,m,i;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        cin>>b[i];
    }
    if(n==1||m==1) cout<<1;
    else{
        a[m-1]+=b[0];
    int ans=m,mid;
    int l=1,r=n-1,temp=0;
    for(i=m-2;i>=0;i--){
        if(a[i]+b[n-1]>=a[m-1]){
            i++;
            break;
        }
        if(l>r || i==0){
            break;
        }
        while(l<=r){
            mid=(l+r)/2;
            if(a[i]+b[mid]<a[m-1]){
                temp=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            } 
        }
        l=temp+1,r=n-1;
        } 
    cout<<i+1;
    }
    
    
    return 0;
}
