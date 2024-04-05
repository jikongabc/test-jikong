#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 1e6 + 10;
int n;
int ans;
int a[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    for (int i = 0; i < n-1;i++){
        if(a[i]!=a[i+1])
            ans++;
    }
    cout << ans+1;

    return 0;
}
