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
const int N = 15;
int n, k;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    cin >> s;
    sort(s.begin(), s.end());
    int res = 0;
    do{
        bool flag = true;
        for (int i = 0; i <= n - k;i++){
            bool pd = true;
            for (int j = 0; j < k/2; j++)
            {
                if(s[i+j]!=s[i+k-1-j]){
                    pd = false;
                    break;
                }
            }
            if(pd){
                flag = false;
                break;
            }
        }
        if(flag)
            res++;

    } while (next_permutation(s.begin(), s.end()));
    cout << res;
    return 0;
}
