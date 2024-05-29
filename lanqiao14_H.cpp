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
#include <cmath>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<double, int> PDI;
const int N = 1e6 + 10;
int n, m;
int l[N], r[N], ll, rr;
int a[N * 2], b[N * 2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> l[i] >> r[i];
        a[l[i] + r[i]]++;
    }
    for (int i = 1; i <= 2*N;i++){
        b[i] = b[i - 1] + a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> ll >> rr;
        cout << b[rr*2] - b[ll*2-1] << endl;
    }

        return 0;
}