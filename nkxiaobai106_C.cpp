#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const int N = 505;
int n;
int g[N][N];

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> g[i][j];
        }
    }
    bool flag = true;
    for(int i = 1; i <= n && flag; i++){
        for(int j = 1; j <= n && flag; j++){
            if(g[i][j] > 0){
                for(int k = 0; k < 4; k++){
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(g[ni][nj] > 0){
                        flag = false;
                        break;
                    }
                }
            }
            else if(g[i][j] < 0){
                for(int k = 0; k < 4; k++){
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(g[ni][nj] < 0){
                        flag = false;
                        break;
                    }
                }
            }
        }
    }
    if(flag) cout << "YES";
    else cout << "NO";
}
