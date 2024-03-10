#include<iostream>
#include<algorithm>
#define int long long
int x[100005];
using namespace std;
signed main(){
    int a,b,c;
    int m[100005];
    cin>>a>>b>>c;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m[i];
        x[m[i]]+=1;
    }
    sort(m,m+n);
    int sum=0;
    for(int i=b+1;i<c;i++){
        sum+=x[i];
    }
    cout<<sum;
    return 0;
}
