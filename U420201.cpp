#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <set>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
const int N = 10005;
LL a[N][N];
LL b[N];
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int flag = 0;
    int x;
    cin >> x;
    for (int i = 0; i < 12;i++){
        for (int j = 1; j <= 6;j++){
            a[i][j] = pow(prime[i], j);
        }
    }
    for (int i = 0; i < 11;i++){
        for (int l = i + 1; l < 12;l++){
            for (int j = 1; j <= 6; j++)
            {
                for (int k = 1; k <= 6; k++)
                {
                    b[flag++] = a[i][j] * a[l][k];
                }
            }
        }
    }
    // for (int i = 0; i < flag;i++)
    //     cout << b[i] << ' ';
        for (int i = 0; i < flag; i++)
        {
            if (x % b[i] == 0)
            {
                x /= b[i];
                i = 0;
            }
        }
    cout << x;
    return 0;
}