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
// const int N =  ;

void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int x, int y){
    int rows = 2, cols = grid[0].size();
    visited[x][y] = true;
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == '.' && !visited[nx][ny]){
            dfs(grid, visited, nx, ny);
        }
    }
}

int cntBlocks(vector<vector<char>> &grid){
    int rows = 2, cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int cnt = 0;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (grid[i][j] == '.' && !visited[i][j]){
                dfs(grid, visited, i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<char>> grid(2, vector<char>(n));
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    int t = cntBlocks(grid);
    int res = 0;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < n; j++){
            if (grid[i][j] == '.'){
                grid[i][j] = 'x';
                int new_t = cntBlocks(grid);
                if (new_t != t){
                    res++;
                }
                grid[i][j] = '.';
            }
        }
    }
    cout << res << endl;
    return 0;
}