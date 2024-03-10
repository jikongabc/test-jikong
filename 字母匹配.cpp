#include<iostream>
#include<cstring>
#include<cmath>
int xiao[10005];
using namespace std;
int main(){
    int count=0;
    int n,k,i;
    cin>>n>>k;
    char c[1000005];
    cin>>c;
    for(i=0;i<strlen(c);i++){
        if(c[i]>='a' && c[i]<='z' ){
            if(xiao[c[i]-'a']<0) count++; 
            xiao[c[i]-'a']++;
        }
        else if(c[i]>='A' && c[i]<='Z'){
            if(xiao[c[i]-'A']>0)  count++;
            xiao[c[i]-'A']--;
        }
    }
    for(i=0;i<26;i++){
        xiao[i]=abs(xiao[i]);
        if(k<=0) break;
        else{
            while(xiao[i]>=2){
                xiao[i]-=2;
                k--;
                count++;
            }
        }
    }
    cout<<count;
}
