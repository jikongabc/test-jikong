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
int primes[N], cnt;
int phi[N];
bool st[N];
void get_phi(int n){
    phi[1] = 1;
    for (int i = 2; i <= n;i++){
        if(!st[i]){
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i;j++){
            st[primes[j] * i] = 1;
            if(i%primes[j]==0){
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    LL ans = 0;
    get_phi(n);
    for (int i = 1; i <= n;i++)
        ans += phi[i];
    cout << ans;
    return 0;
}