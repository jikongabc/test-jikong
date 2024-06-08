#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int n;
int dp[N];
bool st[N];

int get_sum(int n){
    int sum = 0;
    while(n){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        dp[i] = dp[i - 1];
        if(i<10 && i%2==0){
            dp[i] = dp[i - 1] + 1;
            st[i] = 1;
        }
        int t = get_sum(i);
        if(t<i){
            if(st[t] && t%2==0){
                dp[i] += 1;
                st[i] = 1;
            }    
        }
    }
    cout << dp[n];
    return 0;   
}