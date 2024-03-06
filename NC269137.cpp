#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char a[100005];
    cin>>a;
    for(int i=0;i<strlen(a)/2;i++) cout<<a[i];
    cout<<endl;
    for(int i=strlen(a)/2;i<strlen(a);i++) cout<<a[i];
    return 0;
}
