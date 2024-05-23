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
int n;

int phi(int n){
    int res = n;
    for (int i = 2; i <= n / i;i++){
        if(n%i==0){
            res = res / i * (i - 1);
            while(n%i==0)
                n /= i;
        }
    }
    if(n>1)
        res = res / n * (n - 1);
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        cout << phi(n) << endl;
    }
    return 0;   
}