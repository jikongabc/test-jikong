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

LL qmi(int a,int k,int p){
    LL res = 1;
    while(k){
        if(k&1)
            res = res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        LL a, p;
        cin >> a >> p;
        if(a%p==0)
            cout << "impossible\n";
        else
            cout << qmi(a, p - 2, p) << endl;
    }
    return 0;
}