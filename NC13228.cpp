#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int n,i;
    double T,C;
    double a[100005],b[100005];
    cin>>n;
    cin>>T>>C;
    double minn=1e9,maxn=0;
    double sum=T*C*1.0,temp=C*1.0;
    for(i=0;i<n;i++){
        cin>>a[i]>>b[i];
        sum+=a[i]*b[i];
        temp+=b[i];
        minn=min(minn,a[i]);
        maxn=max(maxn,a[i]);
    }
    double num=sum*1.0/temp*1.0;
    if(num<=minn){
        cout<<"Possible"<<endl;
        printf("%.4lf\n",minn);
    }
    else if(num>=maxn){
        cout<<"Possible"<<endl;
        printf("%.4lf\n",num);
    }
    else cout<<"Impossible"<<endl;
    return 0;
}
