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
#include <climits>
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
#define lnf LLONG_MAX
#define endl '\n'
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const double pi = acos(-1);
// const int N =  ;
LL n, a, b, c;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> a >> b >> c;
    LL cnt = 0;
    while(true){
        if(n >= a){
            n -= a;
            cnt++;
        }
        else if(n >= b){
            n -= b;
            cnt++;
        }
        else if(n >= c){
            n -= c;
            cnt++;
        }
        else{
            break;
        }
    }
    cout << cnt;
    return 0;
}