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
#define endl '\n'
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const int N = 10;
int n, m, q;
int g[N][N];
int plans[N][N][N];
int selected[N];
int cnt;
int minn = -1;
int ans[N];
int cnt1;

bool check(){
    int res[N][N] = {0};
    for (int k = 0; k < cnt; k++){
        int idx = selected[k];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                res[i][j] |= plans[idx][i][j];
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if ((g[i][j] == 1 && res[i][j] == 1) || (g[i][j] == 0 && res[i][j] == 0)){
                return false;
            }
        }
    }
    return true;
}

void dfs(int pos){
    if (check()){
        if (minn == -1 || cnt < minn){
            minn = cnt;
            cnt1 = cnt;
            for (int i = 0; i < cnt; i++){
                ans[i] = selected[i];
            }
        }
        return;
    }

    if (pos >= q)
        return;

    dfs(pos + 1);

    selected[cnt++] = pos;
    dfs(pos + 1);
    cnt--;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char c;
            cin >> c;
            g[i][j] = c - '0';
        }
    }

    for (int k = 0; k < q; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                char c;
                cin >> c;
                plans[k][i][j] = c - '0';
            }
        }
    }

    cnt = 0;
    dfs(0);

    cout << minn << endl;
    if (minn > 0){
        for (int i = 0; i < cnt1; i++){
            cout << (ans[i] + 1) << (i == cnt1 - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}