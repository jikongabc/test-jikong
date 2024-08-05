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
const int N = 35;
int n, m;
int f[N][10];

void init(){
    for (int i = 0; i <= 9;i++){
        if (i != 4)
            f[1][i] = 1;
    }
    for (int i = 2; i < N;i++){
        for (int j = 0; j <= 9;j++){
            if(j==4)
                continue;
            for (int k = 0; k <= 9;k++){
                if(k!=4 && !(j==6 && k==2)){
                    f[i][j] += f[i - 1][k];
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
            if(j!=4 && !(last==6 && j==2)){
                res += f[i + 1][j];
            }
        }
        if(x==4 ||last==6 && x==2)
            break;
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
    while(cin>>n>>m,n||m){
        cout << dp(m) - dp(n - 1) << endl;
    }
    return 0;
}
