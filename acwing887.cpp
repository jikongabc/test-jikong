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

int qmi(int a,int k,int p){
    int res = 1;
    while(k){
        if(k&1)
            res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>=1;
    }
    return res;
}

int C(LL a,LL b,int p){
    if(b>a)
        return 0;
    if(b>a-b)
        b = a - b;
    LL x = 1, y = 1;
    for (int i = 0; i < b;i++){
        x = x * (a - i) % p;
        y = y * (i + 1) % p;
    }
    return x * qmi(y, p - 2, p) % p;
}

int lucas(LL a,LL b,int p){
    if(a<p && b<p)
        return C(a, b, p);
    return (LL)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        LL a, b;
        int p;
        cin >> a >> b >> p;
        cout << lucas(a, b, p) << endl;
    }
    return 0;
}