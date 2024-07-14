#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    set<int> s;
    set<int>::iterator it;
    int num;
    int a[100005];
    for (int i = 0; i < n;i++){
        cin >> num;
        while(1){
            if(s.find(num) == s.end())
                break;
            num++;
        }
        s.insert(num);
        cout << num << ' ';
    }
    return 0;
}