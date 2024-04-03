#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 1005;
char ch[N][N];
char end1[N][N];
int n, m;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool pd(){
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
if (ch[i][j] != end1[i][j])
                return false;
        }
            
    }
    return true;
}

void solve(){
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            bool judge = 1;
            for (int k = 0; k < 8;k++){
                int a = i + dx[k], b = j + dy[k];
                if(a<0 || b<0 || a>=n || b>=m){
                    judge = 0;
                    break;
                }
                if(end1[a][b]!='#'){
                    judge = 0;
                    break;
                }
                
            }
            if(judge){
                for (int k = 0; k < 8;k++){
                    int a = i + dx[k], b = j + dy[k];
                    ch[a][b] = '#';
                }
            }
            else
                continue;
        }
    }
    // for (int i = 0; i < n;i++){
    //     for (int j = 0; j < m;j++){
    //         cout << ch[i][j];
    //     }
    //     cout << endl;
    // }
        if (pd())
            cout << "YES";
        else
            cout << "NO";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> end1[i][j];
            ch[i][j] = '.';
        }
    }
    solve();
    return 0;
}