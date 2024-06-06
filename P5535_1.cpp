#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 1e5 + 10;
LL n, k;

LL gcd(LL a,LL b){
    return b ? gcd(b, a % b) : a;
}

bool is_prime(LL n){
    if(n<2)
        return false;
    for (LL i = 2; i <= n / i;i++){
        if(n%i==0)
            return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    if(is_prime(k+1)){
        if((n+1)/(k+1)==1)
            cout << 1;
        else
            cout << 2;
    }
    else
        cout << 2;
    return 0;   
}