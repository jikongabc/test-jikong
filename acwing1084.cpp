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
const int N = 11, M = 110;
int a, b, P;
int f[N][N][M];// f[i][j][k]: 共有i位，最高位是j，各位数之和对P取模为k

int mod(int x,int y){
    return ((x % y) + y) % y;
}

void init(){
    memset(f, 0, sizeof f);
    for (int i = 0; i <= 9; i++)
        f[1][i][i % P]++;
    for (int i = 2; i < N;i++){
        for (int j = 0; j <= 9;j++){
            for (int k = 0; k < P;k++){
                for (int x = 0; x <= 9;x++){
                    f[i][j][k] += f[i - 1][x][mod(k - j, P)];
                }
            }
        }
    }
}

int dp(int n){
    if(!n)
        return 1;
    vector<int> nums;
    while(n){
        nums.push_back(n % 10);
        n /= 10;
    }
    int res = 0, last = 0;
    for (int i = nums.size()-1; i >= 0;i--){
        int x = nums[i];
        for (int j = 0; j < x;j++){
            res += f[i + 1][j][mod(-last, P)];
        }
        last += x;
        if(!i && (last%P==0))
            res++;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin>>a>>b>>P){
        init();
        cout << dp(b) - dp(a - 1) << endl;
    }
    return 0;
}
