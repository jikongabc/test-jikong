#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    double ans;
    if(n<7){
        ans=0.0;
    }
    else{
        int num=(n-5)/2;
    ans=0.03;
    double a=ans;
    for(int i=0;i<num-1;i++){
        a*=0.97;
        ans+=a;
        
    }
}
    
    printf("%.3lf",ans);
    return 0;
}




//1  0.03
//2  0.03+0.97*0.03
