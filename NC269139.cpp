#include<iostream>
#include<set>
#define int long long
using namespace std;
signed main(){
    int n;
    cin>>n;
    set<int> a;
    set<int> b;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        if(a.find(num) !=a.end()) b.insert(num);
        else a.insert(num);
    }
    set<int>::iterator it;
    set<int>::iterator it1;
    int temp=1;
//    for (it = a.begin(), it1 = b.begin(); it != a.end(),it1!=b.end(); it++, it1++){
//	if (*it1 != *it){
//        temp=0;
//		break;
//	}
if(a!=b) temp=0;
    if(temp)cout<<-1;
    else{
        for (it = a.begin();it != a.end(); it++){
            cout<<*it<<' ';
        }
        cout<<endl;
        for (it = a.begin(); it != a.end(); it++){
            cout<<*it<<' ';
        }
    } 
        
    return 0;
    }
