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
typedef pair<double, int> PDI;
const int N = 105;
int cnt[N];
int cnt_cpy[N];
int edges[N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    LL T;
    cin >> T;
    while (T--){
        string s;
        memset(cnt, 0, sizeof cnt);
        memset(edges, 0, sizeof edges);
        for (int i = 0; i < 5; i++){
            int a, b;
            cin >> a >> b;
            edges[a][b]++;
            edges[b][a]++;
            cnt[a]++, cnt[b]++;
        }
        memcpy(cnt_cpy, cnt, sizeof cnt);
        sort(cnt + 1, cnt + 6 + 1);
        for (int i = 1; i <= 6; i++){
            s += (cnt[i] + '0');
        }
        if (s == "112222")
            cout << "n-hexane\n";
        // else if (s == "111223")
        //     cout << "3-methylpentane\n";
        else if (s == "111124")
            cout << "2,2-dimethylbutane\n";
        // else if (s == "111223")
        //     cout << "2-methylpentane\n";
        else if (s == "111133")
            cout << "2,3-dimethylbutane\n";
        // cout << s << endl;
        else{
            int ans = 0;
            // int temp;
            // for (int i = 1; i <= 6;i++){
            //     if(cnt[i]==2){
            //         for (int j = 1; j = 6;j++){
            //             for (int k = 1; k <= 6;k++){
            //                 if(edges[j][k]>0){
            //                     if(j==i)
            //                 }
            //             }
            //         }
            //     }
            // }

            for (int i = 1; i <= 6; i++){
                for (int j = 1; j <= 6; j++){
                    if (edges[i][j] > 0 && cnt_cpy[i] == 3 && cnt_cpy[j] == 1){
                        ans++;
                    }
                }
            }
            if (ans == 1)
                cout << "3-methylpentane\n";
            else
                cout << "2-methylpentane\n";
        
            // if (ans==1)
            //     cout << "2-methylpentane\n";
            // else
            //     cout << "3-methylpentane\n";
        }
        
    }
    return 0;
}