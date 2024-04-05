#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
bool hang[20] = {0};
bool pie[30] = {0};
bool na[30] = {0};
int a[30];
int ans;
int total;
int n;
void dfs(int x){
    if (x > n){
        ans++;
        if(total<=2){
            for (int k = 1; k <= n;k++)
                cout << a[k] << ' ';
            cout << endl;
        }
        total++;
        return;
    }
    for (int i = 1; i <= n; i++){
        if (!hang[i] && !na[i - x + n] && !pie[i + x]){
            a[x] = i;
            hang[i] = true;
            na[i - x + n] = true;
            pie[i + x] = true;
            dfs(x + 1);
            hang[i] = false;
            na[i - x + n] = false;
            pie[i + x] = false;
        }
    }
}

int main(){
    // for (int i = 0; i < 11; i++){
    //     ans = 0;
    //     dfs(1, i);
    //     cnt[i] = ans;
    // }
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    dfs(1);
    // while (cin >> n && n != 0){
        cout << ans << endl;
    // }
    return 0;
}