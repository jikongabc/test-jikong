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
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 2010;
const int mod = 1e9 + 7;

int C[N][N];

void init(){
    for (int i = 0; i < N;i++){
        for (int j = 0; j <= i;j++){
            if(!j)
                C[i][j] = 1;
            else
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int T;
    cin >> T;
    while(T--){
        int a, b;
        cin >> a >> b;
        cout << C[a][b] << endl;
    }

    return 0;
}