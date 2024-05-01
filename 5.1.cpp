#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
string s1 = "COFFEE", s2 = "CHICKEN";
ULL len[5005];
ULL n, k;
// string ss[505];

char dfs(ULL n,ULL k){
    if(n==1)
        return s1[k - 1];
    else if(n==2)
        return s2[k - 1];
    if(k>len[n-2])
        return dfs(n - 1, k - len[n - 2]);
    return dfs(n - 2, k);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    len[1] = 6, len[2] = 7;
    for (int i = 3; i <= 500;i++){
        len[i] = len[i - 1] + len[i - 2];
    }
        // ss[1] = s1, ss[2] = s2;
        // for (int i = 3; i <= 10;i++){
        //     ss[i] = ss[i - 2] + ss[i - 1];
        // }
        // cout << s;
        // cout << s.size();
        // for (int i = 1; i <= 10;i++)
        //     cout << ss[i] << endl;
    int T;
    cin >> T;
    while(T--){
        cin >> n >> k;
        for (ULL i = k; i < k + 10 && i <= len[n];i++){
            cout << dfs(n, i);
        }
            //     LL temp = k-1;
            //     while(temp<=ss[n].size()-1 && temp<k+9){
            //         cout << ss[n][temp];
            //         temp++;
            //     }
            cout << endl;
    }
    return 0;
}

// COFFEE
// CHICKEN
// COFFEECHICKEN
// CHICKENCOFFEECHICKEN
// COFFEECHICKENCHICKENCOFFEECHICKEN
// CHICKENCOFFEECHICKENCOFFEECHICKENCHICKENCOFFEECHICKEN
// COFFEECHICKENCHICKENCOFFEECHICKENCHICKENCOFFEECHICKENCOFFEECHICKENCHICKENCOFFEECHICKEN
// CHICKENCOFFEECHICKENCOFFEECHICKENCHICKENCOFFEECHICKENCOFFEECHICKENCHICKENCOFFEECHICKENCHICKENCOFFEECHICKENCOFFEECHICKENCHICKENCOFFEECHICKEN
// COFFEECHICKENCHICKENCOFFEECHICKENCHICKENCOFFEECHICKENCOFFEECHICKENCHICKENCOFFEECHICKENCHICKENCOFFEECHICKENCOFFEECHICKENCHICKENCOFFEECHICKENCOFFEECHICKENCHICKENCOFFEECHICKENCHICKENCOFFEECHICKENCOFFEECHICKENCHICKENCOFFEECHICKEN
// CHICKENCOFFEECHICKENCOFFEECHICKENCHICKENCOFFEECHICKENCOFFEECHICKENCHICKENCOFFEECHICKENCHICKENCOFFEECHICKENCOFFEECHICKENCHICKENCOFFEECHICKENCOFFEECHICKENCHICKENCOFFEECHICKENCHICKENCOFFEECHICKENCOFFEECHICKENCHICKENCOFFEECHICKENCHICKENCOFFEECHICKENCOFFEECHICKENCHICKENCOFFEECHICKENCOFFEECHICKENCHICKENCOFFEECHICKENCHICKENCOFFEECHICKENCOFFEECHICKENCHICKENCOFFEECHICKEN
