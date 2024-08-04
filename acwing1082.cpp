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
const int N = 15;
int f[N][N];//f[i][j] -> 一共有i位且最高位是j的不降数的个数
int a, b;

void init(){
    for (int i = 0; i <= 9;i++)
        f[1][i] = 1;
    for (int i = 2; i < N;i++){
        for (int j = 0; j <= 9;j++){
            for (int k = j; k <= 9;k++){
                f[i][j] += f[i - 1][k];
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
    int last = 0;
    int res = 0;
    for (int i = nums.size() - 1; i >= 0;i--){
        int x = nums[i];
        if(x<last)
            break;
        for (int j = last; j < x;j++)//上一位填x
            res += f[i + 1][j];
        last = x;
        if(!i)
            res++;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    while(cin>>a>>b){
        cout << dp(b) - dp(a - 1) << endl;
    }
    return 0;
}