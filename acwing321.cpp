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
const int N = 9, M = 15;
int n, m = 8;
int s[N][N];
double f[N][N][N][N][M];
double X;

double get(int x1,int y1,int x2,int y2){
    double sum = s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1] - X;
    return sum * sum / n;
}

double dp(int x1,int y1,int x2,int y2,int k){
    double &t = f[x1][y1][x2][y2][k];
    if(t>0)
        return t;
    if(k==n)
        return get(x1, y1, x2, y2);
    t = inf;
    for (int i = x1; i < x2;i++){
        t = min(t, dp(x1, y1, i, y2, k + 1) + get(i + 1, y1, x2, y2));
        t = min(t, dp(i + 1, y1, x2, y2, k + 1) + get(x1, y1, i, y2));
    }
    for (int i = y1; i < y2;i++){
        t = min(t, dp(x1, y1, x2, i, k + 1) + get(x1, i + 1, x2, y2));
        t = min(t, dp(x1, i + 1, x2, y2, k + 1) + get(x1, y1, x2, i));
    }
    return t;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= m;i++){
        for (int j = 1; j <= m;j++){
            cin >> s[i][j];
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    memset(f, -1, sizeof f);
    X = (double)s[m][m] / n;
    printf("%.3lf\n", sqrt(dp(1, 1, 8, 8, 1)));
    return 0;
}