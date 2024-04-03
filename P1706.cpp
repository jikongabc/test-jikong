#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<deque>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
int n;
int a[10];
int st[10];
void dfs(int x){
    if(x>n){
        for (int i = 1; i <= n;i++){
            printf("%5d",a[i]);
        }
        cout << endl;
    }
    for (int i = 1; i <= n;i++){
        if(!st[i]){
            a[x] = i;
            st[i] = 1;
            dfs(x + 1);
            st[i] = 0;
        }
    }

}
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    cin >> n;
    dfs(1);
    return 0;
}