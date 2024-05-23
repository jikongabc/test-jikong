#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;

bool is_prime(int n){
    for (int i = 2; i <= n / i;i++){
        if(n%i==0)
            return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        if(is_prime(n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}