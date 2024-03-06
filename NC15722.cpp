#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n;
        int temp=1;
        while(n--){
            cin>>s;
            if(s.compare("PERFECT")){
                temp=0;
            }
        }
        if(temp) cout<<"MILLION Master"<<endl;
        else cout<<"NA Noob"<<endl;
    }
    return 0;
}
