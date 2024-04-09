#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 105;
int n;
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {-1, 0, 1, -1, 1, 1, 0, -1};
int a[N][N];
string p[N];
string s = "yizhong";
int xx[N], yy[N];

void solve(int x,int y){
    for (int i = 0; i < 8;i++){
        int temp = 0;
        for (int j = 0; j < 7;j++){
            xx[j] = x + j * dx[i], yy[j] = y + j * dy[i];
            // if(xx[j]<=0 || yy[j]<0 || xx[j]>n || yy[j]>=n)
            //     continue;
            if(p[xx[j]][yy[j]]!=s[j]){
                temp = 1;
                break;
            }
        }
        if (!temp){
            for (int j = 0; j < 7; j++){
                xx[j] = x + j * dx[i], yy[j] = y + j * dy[i];
                a[xx[j]][yy[j]] = 1;
            }
            a[x][y] = 1;
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> p[i];
    }
    for (int i = 1; i <= n;i++){
        for (int j = 0; j < n;j++){
            if(p[i][j]=='y')
                solve(i, j);
            // cout << i << j << endl;
        }
    }
    for (int i = 1; i <= n;i++){
        for (int j = 0; j < n;j++){
            if(a[i][j])
                cout << p[i][j];
            else
                cout << '*';
        }
        cout << endl;
    }
        return 0;
}