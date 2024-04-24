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
const int N = 5005;
int n;

vector<int> get_divisors(int x){
    vector<int> res;
    for (int i = 1; i <= x / i;i++){
        if(x%i==0){
            res.push_back(i);
            if(i!=x/i)
                res.push_back(x / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        auto res = get_divisors(x);
        for(auto x:res)
            cout << x << ' ';
        cout << endl;
    }
    return 0;
}