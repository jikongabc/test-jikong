#include <iostream>
#include <sstream>
#include <algorithm>
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
typedef pair<double, int> PDI;
typedef pair<PII, int> PIII;
const int N = 1005;
int n, m;
int x[N], y[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int pie = 0, na = 0;
    for (int i = 1; i <= m;i++){
        int a;
        cin >> a;
        a--;
        int xx = a / n, yy = a % n;
        x[xx]++;
        y[yy]++;
        if(xx==yy)
            na++;
        if(xx+yy==n-1)
            pie++;
        if(x[xx]==n ||  y[yy]==n || pie==n || na==n){
            cout << i;
            return 0;
        }
    }
    cout << -1;

    return 0;
}