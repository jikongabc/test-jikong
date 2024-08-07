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
const int N = 9, M = 1 << N;
int p[N][N];
int row[N], col[N], cell[3][3];
int cnt1[M], map1[M];

void init(){
    for (int i = 0; i < N;i++)
        row[i] = col[i] = (1 << N) - 1;
    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 3; j++){
            cell[i][j] = (1 << N) - 1;
        }
    }
}

int lowbit(int x){
    return x & -x;
}
int get(int x,int y){
    return row[x] & col[y] & cell[x / 3][y / 3];
}

void draw(int x,int y,int t,bool pd){
    if(pd)
        p[x][y] = t + 1;
    else
        p[x][y] = 0;
    int v = 1 << t;
    if(!pd)
        v = -v;
    row[x] -= v;
    col[y] -= v;
    cell[x / 3][y / 3] -= v;
}

bool dfs(int cnt){
    if(!cnt)
        return true;
    int minn = 10, x, y;
    for (int i = 0; i < N;i++){
        for (int j = 0; j < N;j++){
            if(!p[i][j] && cnt1[get(i,j)]<minn){
                minn = cnt1[get(i, j)];
                x = i, y = j;
            }
        }
    }
    int state = get(x, y);
    for (int i = state; i;i-=lowbit(i)){
        int t = map1[lowbit(i)];
        draw(x, y, t, true);
        if(dfs(cnt-1))
            return true;
        draw(x, y, t, false);
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < N;i++)
        map1[1 << i] = i;
    for (int i = 0; i < M;i++){
        for (int j = 0; j < N;j++){
            cnt1[i] += i >> j & 1;
        }
    }
    init();
    int cnt = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            int t;
            cin >> t;
            if (!t)
                cnt++;
            else
                draw(i, j, t - 1, true);
        }
    }
    dfs(cnt);
    for (int i = 0; i < N;i++){
        for (int j = 0; j < N;j++){
            cout << p[i][j] << ' ';
        }
        cout << endl;
    }
        return 0;
}
