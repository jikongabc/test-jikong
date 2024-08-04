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
const int N = 35;
int x, y, k, b;
int C[N][N];

int dp(int n){
    vector<int> nums;
    while(n){
        nums.push_back(n % b);
        n /= b;
    }
    int res = 0;
    int last = 0;
    for (int i = nums.size() - 1; i >= 0;i--){
        int x = nums[i];
        if(x){
            res += C[i][k - last];
            if(x>1){
                res += C[i][k - last - 1];
                break;
            }
            else if(x==1){
                last++;
                if(last>k)
                    break;
            }
        }
        if (!i && last == k)
            res++;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> x >> y >> k >> b;
    for (int i = 0; i <= N;i++){
        for (int j = 0; j <= i;j++){
            if(!j)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    cout << dp(y) - dp(x - 1);
    return 0;
}