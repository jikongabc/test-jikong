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
#define int long long
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 5;
int n, m;
int a[N][N];

int determinant(vector<vector<int>> &matrix, int n)
{
    int det = 0;
    if (n == 1)
        return matrix[0][0];
    if (n == 2)
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    vector<vector<int>> submatrix(n, vector<int>(n));
    int sign = 1;
    for (int p = 0; p < n; p++)
    {
        int subi = 0;
        for (int i = 1; i < n; i++)
        {
            int subj = 0;
            for (int j = 0; j < n; j++)
            {
                if (j == p)
                    continue;
                submatrix[subi][subj] = matrix[i][j];
                subj++;
            }
            subi++;
        }
        det += sign * matrix[0][p] * determinant(submatrix, n - 1);
        sign = -sign;
    }
    return det;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int res = inf;
    int minn = min(n, m);
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> a[i][j];
            res = min(res, a[i][j]);
        }
    }
    if(minn>=2){
        res = min(res, a[0][0] * a[1][1] - a[1][0] * a[0][1]);
    }
    if(minn>=3){
        int i = 0, j = 0;
        int res_a = a[i][j] * a[i + 1][j + 1] * a[i + 2][j + 2] + a[i][j + 1] * a[i + 1][j + 2] * a[i + 2][j] + a[i][j + 2] * a[i + 1][j] * a[i + 2][j + 1];
        int res_b = a[i][j + 2] * a[i + 1][j + 1] * a[i + 2][j] + a[i][j] * a[i + 2][j + 1] * a[i + 1][j + 2] + a[i][j + 1] * a[i + 1][j] * a[i + 2][j + 2];
        res = min(res, res_a - res_b);
    }
    if(minn>=4){
        vector<vector<int>> submatrix(4, vector<int>(4));
        for (int x = 0; x < 4; x++)
        {
            for (int y = 0; y < 4; y++)
            {
                submatrix[x][y] = a[x][y];
            }
        }
        res = min(res, determinant(submatrix, 4));
    }
    if(minn==5){
        
                vector<vector<int>> submatrix(5, vector<int>(5));
                for (int x = 0; x < 5; x++)
                {
                    for (int y = 0; y < 5; y++)
                    {
                        submatrix[x][y] = a[x][y];
                    }
                }
                res = min(res, determinant(submatrix, 5));
        
    }
    int maxnn = max(n, m);
    vector<vector<int>> submatrix(maxnn, vector<int>(maxnn));
    for (int i = 0; i < maxnn;i++){
        for (int j = 0; j < maxnn;j++){
            submatrix[i][j] = a[i][j];
        }
    }
    res = min(res, determinant(submatrix, maxnn));
    cout << res;

    return 0;
}
