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
const int N = 1e5 + 10;
int res;
int primes[N], cnt;
bool st[N];
int n;

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
    if (n < 2)
    {
        cout << 0 << endl;
        return 0;
    }
    else if (n == 2)
    {
        cout << 2 << endl
             << 1 << endl;
        return 0;
    }
    get_primes(N);
    int i;
    for (i = 0; i <= cnt;i++){
        if(res+primes[i]>n)
            break;
        res += primes[i];
        cout << primes[i] << endl;
    }
    cout << i;
    return 0;
}