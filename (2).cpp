#include<iostream>
#include<cmath>
#include<set>
#define int long long
using  namespace std;
bool zhishu(int n){
    for(int i=2;i*i<n;i++){
        if( n%i==0|| n!=1) return true;
    }
    return false;
}
int kate(int n){
    if(n==1 || n==0) return 1; 
    int sum=0;
    for(int i=0;i<n-1;i++){
        sum+=kate(i)*kate(i-1);
    }
    return sum;
}
bool kate1(int n){
    set<int> s;
    for(int i=1;i<=10000;i++){
        s.insert(kate(i));
    }
    if(s.find(n)!=s.end()) return true;
    return false;
}
signed main(){
    int n;
    cin>>n;
    int count=0;
    for(int i=1;i<=n;i+=2){
        if(zhishu(i)) continue;
        if(kate1(i)) continue;
        count++;
    }
    cout<<count;
    return 0;
}
// C0=C1=1
// C2=2
// C3=5
// C4=14
// C5=42

//C3=C0*C2+C1*C1+C2*C0
//C4=C0*C3+C1*C2+C2*C1+C3*C0
//C5=C0*C4+C1*C3+C2*C2+C3*C1+C4*C0
