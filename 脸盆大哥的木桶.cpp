#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,s,temp=0;
        cin>>n>>k>>s;
        int a[1005];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        if(n%k==0){
            for(int i=0;i<n;i+=k){
                temp+=a[i];
            }
        }
        else{
            for(int i=n%k;i<n;i+=k){
                temp+=a[i];
            }
        }
        cout<<temp*s<<endl;
    }
    return 0;
}
