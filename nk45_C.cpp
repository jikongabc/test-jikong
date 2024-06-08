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
int n;

int get_sum(int n){
    int sum = 0;
    while(n){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool is_good(int n){
    int sum = get_sum(n);
    if(sum%2==0){
        if(sum<n){
            return is_good(sum);
        }
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n;i++){
        if(is_good(i))
            res++;
    }
    cout << res;
    return 0;
}