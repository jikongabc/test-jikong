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
char ch[100];
int row[N], col[N], ceil[3][3];//行 列 九宫格二进制状态->1:能填  0:不能填
int cnt1[M], map1[N];//cnt1:log2   map1:1的个数

void init(){//初始化
    for (int i = 0; i < N;i++)
        row[i] = col[i] = (1 << N) - 1;
    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 3;j++){
            ceil[i][j] = (1 << N) - 1;
        }
    }
}

int lowbit(int x){//二进制最后一位1
    return x & -x;
}

int get(int x,int y){//当前位置可以填的数
    return row[x] & col[y] & ceil[x / 3][y / 3];
}

void draw(int x,int y,int t,bool pd){
    if(pd)
        ch[x * N + y] = t + '1';
    else
        ch[x * N + y] = '.';
    int v = 1 << t;
    if(!pd)
        v = -v;
    row[x] -= v;
    col[y] -= v;
    ceil[x / 3][y / 3] -= v;
}

bool dfs(int cnt){
    if(!cnt)
        return true;
    int minn = 10, x, y;
    for (int i = 0; i < N;i++){
        for (int j = 0; j < N;j++){
            if(ch[i*N+j]=='.' && cnt1[get(i,j)]<minn){
                minn = cnt1[get(i, j)];
                x = i, y = j;
            }
        }   
    }
    int state = get(x, y);
    for (int i = state; i; i -= lowbit(i)){
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
    // 预处理
    for (int i = 0; i < N; i++)
        map1[1 << i] = i;
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            cnt1[i] += i >> j & 1;
        }
    }
    while(cin>>ch,ch[0]!='e'){
        init();
        int cnt = 0;
        for (int i = 0; i < N;i++){
            for (int j = 0; j < N;j++){
                if(ch[i*N+j]!='.')
                    draw(i, j, ch[i * N + j] - '1', true);
                else
                    cnt++;
            }
        }
        dfs(cnt);
        cout << ch << endl;
    }
    return 0;
}
