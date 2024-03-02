#include<iostream>
#define int long long
using namespace std;
bool pd(int a,int b,int c,int mid){
    a-=mid;
    b-=mid;
    if(a<0||b<0) return false;
    if(a+b+c<mid) return false;
    if(a>b) swap(a,b);
    if(b>c) swap(b,c);
    if(a+b<mid/2) return false;
    return true;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int l=0,r=min(a,b);
        int ans,mid;
        while(l<=r){
            mid=(l+r)/2;
            if(pd(a,b,c,mid)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
