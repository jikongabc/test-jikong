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
const int N = 1e8 + 10;
int n, q;
int primes[N], cnt;
bool st[N];

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
    cin >> n >> q;
    get_primes(n);
    while(q--){
        int a;
        cin >> a;
        cout << primes[a-1] << endl;
    }
    return 0;
}