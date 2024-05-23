#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 1e6 + 10;

LL exgcd(LL a,LL b, LL &x, LL &y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        LL a, b, m;
        cin >> a >> b >> m;
        LL x, y;
        LL d = exgcd(a, m, x, y);
        if(b%d)
            cout << "impossible\n";
        else
            cout << b / d * x % m << endl;
    }
    return 0;
}