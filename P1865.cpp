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
const int N = 1e6 + 10;
int cnt[N];

bool is_primes(int n){
    if(n<2)
        return false;
    for (int i = 2; i <= n / i;i++){
        if(n%i==0)
            return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m;i++){
        if(is_primes(i))
            cnt[i] = cnt[i - 1] + 1;
        else
            cnt[i] = cnt[i - 1];
    }
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        if(a<1 || b> m){
            cout << "Crossing the line\n";
            continue;
        }
        cout << cnt[b] - cnt[a - 1] << endl;
    }
    return 0;
}