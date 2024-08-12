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
const int N = 26;
int n, m;
bool g[N][N], d[N][N];
bool st[N];

void floyd(){
    memcpy(d, g, sizeof d);
    for (int k = 0; k < n;k++){
        for (int i = 0; i < n;i++){
            for (int j = 0; j < n;j++){
                d[i][j] |= d[i][k] && d[k][j];
            }
        }
    }
}

int check(){
    for (int i = 0; i < n;i++){
        if(d[i][i])
            return 2;
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            if(!d[i][j] && !d[j][i] && i!=j)
                return 0;
        }
    }
    return 1;
}

char get_min(){
    for (int i = 0; i < n;i++){
        if(!st[i]){
            bool flag = true;
            for (int j = 0; j < n; j++){
                if(!st[j] && d[j][i]){
                    flag = false;
                    break;
                }
            }
            if (flag){
                st[i] = true;
                return i + 'A';
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int res;
    while (cin >> n >> m,n||m){
        int flag = 0;
        memset(g, false, sizeof g);
        string op;
        for (int i = 1; i <= m;i++){
            cin >> op;
            if(!flag){
                g[op[0] - 'A'][op[2] - 'A'] = 1;
                floyd();
                flag = check();
                if(flag)
                    res = i;
            }
        }
        if(!flag)
            cout << "Sorted sequence cannot be determined.\n";
        else if(flag==2)
            cout << "Inconsistency found after " << res << " relations.\n";
        else{
            memset(st, false, sizeof st);
            cout << "Sorted sequence determined after " << res << " relations: ";
            for (int i = 0; i < n;i++)
                cout << get_min();
            cout << ".\n";
        }
            
    }
        return 0;
}
