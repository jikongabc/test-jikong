#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
using LL = long long;
const int N = 505;
int n, m, k;
int a[N][N];
LL sum[N][N];
LL sum1[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> a[i][j];
        }
    }
    for (int j = 1; j <= m;j++){
        for (int i = 1; i <= n;i++){
            sum[i][j] = sum[i - 1][j] + a[i][j];
        }
    }
    int ans = 0;
    for (int l = 1; l <= n;l++){
        for (int r = l; r <= n;r++){
            for (int j = 1; j <= m;j++){
                sum1[j] = sum[r][j] - sum[l - 1][j];
            }
            LL temp_sum = 0;
            for (int i = 1, j = 1; i <= m;i++){
                temp_sum += sum1[i];
                while(temp_sum>k && i>=j){
                    temp_sum -= sum1[j];
                    j++;
                }
                ans += i - j + 1;
            }
        }
    }
    cout<<ans;
    return 0;
}
