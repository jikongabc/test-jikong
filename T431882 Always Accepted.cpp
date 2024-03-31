#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    LL a, b;
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << a + b << '\n';
    }
    return 0;
}