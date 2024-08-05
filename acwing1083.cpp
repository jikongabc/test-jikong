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
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 11;
int a, b;
int f[N][N];

void init(){
    for (int i = 0; i <= 9;i++)
        f[1][i] = 1;
    for (int i = 2; i <= N;i++){
        for (int j = 0; j <= 9;j++){
            for (int k = 0; k <= 9;k++){
                if(abs(j-k)>=2)
                    f[i][j] += f[i - 1][k];
            }
        }
    }
}

int dp(int n){
    vector<int> nums;
    while(n){
        nums.push_back(n % 10);
        n /= 10;
    }
    int res = 0, last = -2;
    //等于num.size()的windy数
    for (int i = nums.size() - 1; i >= 0;i--){
        int x = nums[i];
        for (int j = i == nums.size() - 1; j < x;j++){
            if(abs(j-last)>=2)
                res += f[i + 1][j];
        }
        if(abs(x-last)>=2)
            last = x;
        else
            break;
        if(!i)
            res++;
    }
    for (int i = 1; i < nums.size();i++){
        for (int j = 1; j <= 9;j++){
            res += f[i][j];
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cin >> a >> b;
    cout << dp(b) - dp(a - 1);
    return 0;
}
