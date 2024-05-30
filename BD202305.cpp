#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<double, int> PDI;
int a, b;

LL qmi(int a,int b,int p){
    LL res = 1 % p;
    while(b){
        if(b&1)
            res = res * a % p;
        a = a * (LL)a % p;
        b >> 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> a >> b;
        if(b==0){
            cout << 0 << endl;
            continue;
        }
        cout << b - (b - 1) / a << endl;
    }
    return 0;   
}