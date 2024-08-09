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
const int N = 24;
int q[N];
int path[100];
int op[8][7] = {
    {0, 2, 6, 11, 15, 20, 22},
    {1, 3, 8, 12, 17, 21, 23},
    {10, 9, 8, 7, 6, 5, 4},
    {19, 18, 17, 16, 15, 14, 13},
    {23, 21, 17, 12, 8, 3, 1},
    {22, 20, 15, 11, 6, 2, 0},
    {13, 14, 15, 16, 17, 18, 19},
    {4, 5, 6, 7, 8, 9, 10}};
int opposite[8] = {5, 4, 7, 6, 1, 0, 3, 2};
int center[8] = {6, 7, 8, 11, 12, 15, 16, 17};

int f(){
    int sum[4] = {0};
    for (int i = 0; i < 8;i++)
        sum[q[center[i]]]++;
    return 8 - max({sum[1], sum[2], sum[3]});
}

void operate(int x){
    int t = q[op[x][0]];
    for (int i = 0; i < 6;i++)
        q[op[x][i]] = q[op[x][i + 1]];
    q[op[x][6]] = t;
}

bool dfs(int u,int depth,int last){
    if(u+f()>depth)
        return false;
    if(!f())
        return true;
    for (int i = 0; i < 8;i++){
        if(opposite[i]!=last){
            path[u] = i;
            operate(i);
            if(dfs(u+1,depth,i))
                return true;
            operate(opposite[i]);
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin>>q[0],q[0]){
        for (int i = 1; i < N;i++)
            cin >> q[i];
        int depth = 0;
        while(!dfs(0,depth,-1))
            depth++;
        if(!depth)
            cout << "No move needed";
        else
            for (int i = 0; i < depth;i++)
                cout << (char)(path[i] + 'A');
        cout << '\n'
             << q[6] << endl;
    }
    return 0;
}
