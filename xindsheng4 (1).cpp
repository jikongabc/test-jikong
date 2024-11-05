#include<iostream>
#include<string.h>
using namespace std;
char a[105][105];
int main(){
    int n,m;
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int num=0;
            char q='1',w='1',e='1',r='1';
            if(a[i][j]=='!'){
                if(a[i-1][j]=='#')  a[i-1][j]=q,q++;
                if(a[i][j-1]=='#')  a[i][j-1]=w,w++;
                if(a[i][j+1]=='#')  a[i][j+1]=e,e++;
                if(a[i+1][j]=='#')  a[i+1][j]=r,r++;
                a[i][j]='@';
            }
            if(a[i][j]=='&'){
                if(a[i-1][j]=='!')  num++;
                if(a[i][j-1]=='!')  num++;
                if(a[i][j+1]=='!')  num++;
                if(a[i+1][j]=='!')  num++;
                if(num==0)  a[i][j]='&';
                else
                a[i][j]=num+48;
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}
