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
int a[N];
int res[N];
int stk[N], top;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    for (int i = n - 2; i >= 0;i--){
        while(top && stk[top]<a[i+1])
            top--;
        stk[++top] = a[i+1];
        res[i] = top;
    }
    for (int i = 0; i < n;i++)
        cout << res[i] << ' ';

        return 0;
}