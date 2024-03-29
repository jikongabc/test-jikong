#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;
void print1(){
    cout << "##";
}
void print2(){
    cout << "..";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int  b = 1;
        while(b<=2*n){
            int a = 1;
            while(a<=n){
                if(b%4 !=0 && b%4!=3){
                    if (a % 2 == 0)
                        print2();
                    else
                        print1();
                }
                else{
                    if (a % 2 != 0)
                        print2();
                    else
                        print1();
                }
                
                a++;
            }
            cout << endl;
            b++;
        }
    }
    
    return 0;
}