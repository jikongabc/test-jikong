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
#include <bitset>
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 2e5 + 10;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<int> v;
    vector<int> res;
    while(n){
        v.push_back(n % 3);
        n /= 3;
    }
    
    for (int i = 0; i < v.size();i++){
        while(v[i]){
            res.push_back(i);
            v[i]--;
        }
    }
    cout << res.size() << endl;
    for(auto i:res)
        cout << i << ' ';
    return 0;
}