//#include<iostream>
//using namespace std;
//int main(){
//    char a;
//    cin>>a;
//    if(a=='A' || a=='B' ||a=='C'){
//        cout<<"YES";}
//        else cout<<"NO";
//        return 0;
//    
//}


//#include<iostream>
//#include<cstring>
//using namespace std;
//int main(){
//    string a,b,c;
//    cin>>a>>b>>c;
//    if(a[0]=='V'){
//        if(b[0]=='B'){
//            if(c[0]=='C') cout<<"Eagle";
//            else cout<<"Pigeons";
//        }
//        else{
//            if(c[1]=='a') cout<<"People";
//            else cout<<"Cow";
//        }
//    }
//    else{
//        if(b[0]=='I'){
//            if(c[0]=='B') cout<<"Fleas";
//            else cout<<"Caterpillar";
//        }
//        else{
//            if(c[0]=='B') cout<<"Leeches";
//            else cout<<"Worms";
//        }
//    }
//    return 0;
//}


//#include<iostream>
//#define int long long
//using namespace std;
//int a[1000000];
//signed main(){
//    int t;
//    cin>>t;
//    while(t--){
//        int n;
//        cin>>n;
//        int sum=0,temp=0;
//        for(int i=1;i<=n;i++) {
//            cin>>a[i];
//            if(a[i]%2 !=0) temp=1;
//            sum+=a[i];
//        }
//        if(sum%2!=0) cout<<"halo"<<endl;
//        else {
//            if(temp) cout<<"halo"<<endl;
//            else cout<<"parry"<<endl;
//        }
//    }
//    return 0;
//}



#include<iostream>
#include<cstring>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;
int main(){
    deque<char> q;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    string s;
    for(int i=0;i<m;i++){
        char ch;
        cin>>ch;
        q.push_front(ch);
    }
    int count=0;
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            count++;
        }
        if(op==2){
            int p;
            cin>>p;
            if(p==1){
               if(count%2==0){
                   char ch1;
                   cin>>ch1;
                   q.push_front(ch1);
               }
                else{
                    char ch2;
                    cin>>ch2;
                    q.push_back(ch2);
                }
            }
            else{
                if(count%2==0){
                    char ch3;
                    cin>>ch3;
                    q.push_back(ch3);
                }
                else{
                    char ch4;
                    cin>>ch4;
                    q.push_front(ch4);
                }
            }
        }
        while(!q.empty()){
            if(count%2==0){
                cout<<q.front();
                q.pop_front();
            } 
            else {
                cout<<q.back();
                q.pop_back();
				}
        }
    }
	return 0;
}
