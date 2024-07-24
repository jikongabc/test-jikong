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
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1e5 + 10;
string s;
int res = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cin >> s;
    if(n<5){
        cout << 0;
        return 0;
    }
    // for (int i = 0; i <= s.size()-5;i++){
    //     if(s.substr(i,5)=="chuan")
    //         res++;
    // }
    cout << res;
    return 0;
}