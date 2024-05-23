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
bool st[N];

// void get_primes(int n){
//     for (int i = 2; i <= n;i++){
//         if(st[i])
//             continue;
//         primes[cnt++] = i;
//         for (int j = i * 2; j <= n;j+=i)
//             st[j] = 1;
//     }
// }

void get_primes(int n){
    for (int i = 2; i <= n;i++){
        if(!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i;j++){
            st[primes[j] * i] = 1;
            if(i%primes[j]==0)
                break;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    get_primes(n);
    cout << cnt;
    return 0;
}