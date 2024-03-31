#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 205;
int a[N];
vector<int> b;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, s, c;
    cin >> m >> s >> c;
    if(m>=c){
        cout << c;
        return 0;
    }
    for (int i = 1; i <= c;i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + c);
    int ans = a[c] - a[1] + 1;
    for (int i = 2; i <= c;i++){
        if (a[i] - a[i - 1] > 1)
        b.push_back(a[i] - a[i - 1]-1);
    }
    sort(b.begin(), b.end(), greater<int>());
    for (int i = 0; i < m-1;i++){
        // cout << b[i] << ' ';
        ans -= b[i];
    }
    cout << ans;
    return 0;
}