#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 110, mod = 1e9 + 7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    unordered_map<int, int> primes;
    while(n--){
        int x;
        cin >> x;
        for (int i = 2; i <= x / i;i++){
            while(x%i==0){
                x /= i;
                primes[i]++;
            }
        }
        if(x>1)
            primes[x]++;
    }
    LL res = 1;
    for(auto p:primes)
        res = res * (p.second + 1) % mod;
    cout << res;
    return 0;
}