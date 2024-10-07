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
int n, m, q;

void solve(){
    cin >> n >> m >> q;

    vector<int> a(n + 1), b(m + 1);
    unordered_map<int, int> id;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        id[a[i]] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }

    int last = 0;
    bool flag = true;

    for (int i = 1; i <= m; i++)
    {
        int t = b[i];
        int now = id[t];

        if (now <= last + 1)
        {
            last = max(last, now);
        }
        else
        {
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "YA" << endl;
    else
        cout << "TIDAK" << endl;
}


int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}