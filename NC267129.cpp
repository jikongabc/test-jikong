#include<iostream>
#include<algorithm>
#include<map>
#define int long long
using namespace std;
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,i;
        int a[100005],b[100005];
        map<int,int>m;
        int temp=1;
        cin>>n;
        for(i=0;i<n;i++){
            cin>>a[i];
            m[a[i]]=0;
        }
        for(i=0;i<n;i++){
            cin>>b[i];
            if(m[a[i]]==0){
                m[a[i]]=b[i];
            } 
            else{
                if(m[a[i]]!=b[i]){
                    temp=0;
                }
            }
        } 
        if(temp) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
