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
const int N = 1e6 + 10;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if(n==1) {
        cout << 0;
        return 0;
    }
    if(n==2){
        cout << 2;
        return 0;
    }
    if(n==3){
        cout << 4;
        return 0;
    }
    if(n&1)
        cout << 6;
    else
        cout << 4;
    return 0;
}