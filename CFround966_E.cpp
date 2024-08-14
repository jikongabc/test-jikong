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
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k, w;
        cin >> n >> m >> k >> w;

        vector<int> a(w);
        for (int i = 0; i < w; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        vector<vector<int>> d(n, vector<int>(m, 0));
        for (int i = 0; i <= n - k; i++){
            for (int j = 0; j <= m - k; j++){
                for (int x = i; x < i + k; x++){
                    for (int y = j; y < j + k; y++){
                        d[x][y]++;
                    }
                }
            }
        }

        priority_queue<int> pq;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (d[i][j] > 0){
                    pq.push(d[i][j]);
                }
            }
        }

        LL res = 0;
        for (int i = 0; i < w && !pq.empty(); i++){
            int top = pq.top();
            pq.pop();
            res += static_cast<LL>(top) * a[i];
        }

        cout << res << endl;
    }
    return 0;
}
