#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e7 + 10;
int n;
int primes[N], cnt;
bool st[N];
bool sst[N];
LL sum[N];

bool is_prime(int x){
    if (x < 2)
        return false;
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0)
            return false;
    return true;
}

void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i]){
            primes[cnt++] = i;
            sst[i] = 1;
        }
            
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    get_primes(N);
    sum[2] = 1;
    for (int i = 3; i <= N; i++)
    {
        if (i % 2 == 0)
        {
            if (sst[i])
                sum[i] = sum[i - 1] + 1;
            else
                sum[i] = sum[i - 1] + 2;
        }
        else
        {
            if (sst[i])
                sum[i] = sum[i - 1] + 1;
            else if (sst[i - 2])
                sum[i] = sum[i - 1] + 2;
            else
                sum[i] = sum[i - 1] + 3;
        }
    }
    while(T--){
        cin >> n;
        cout<<sum[n]<<'\n';
    }
    return 0;
}