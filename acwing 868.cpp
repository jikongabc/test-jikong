#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e6 + 10;
int n;
int primes[N], cnt;
bool st[N];
// void get_primes(int n){
//     for (int i = 2; i <= n;i++){
//         if(st[i])
//             continue;
//         primes[cnt++] = i;
//         for (int j = i + i; j <= n;j+=i)
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
    cin >> n;
    get_primes(n);
    cout << cnt;
    return 0;
}