#include<iostream>
#define int long long
using namespace std;
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,minn=9999999999;
        int a[505];
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n-1;i++){
            minn=min(minn,a[i+1]-a[i]);
        }
        if(minn>=0){
            cout<<minn/2+1<<endl;
}
        else cout<<0<<endl;
        
    }
    return 0;
}
