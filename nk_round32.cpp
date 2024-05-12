// // #include <iostream>
// // #include <algorithm>
// // #include <cstring>
// // #include <string>
// // #include <vector>
// // #include <queue>
// // #include <deque>
// // #include <map>
// // #include <set>
// // #include <unordered_map>
// // #define inf 0x3f3f3f3f
// // using namespace std;
// // using LL = long long;
// // using ULL = unsigned long long;
// // typedef pair<int, int> PII;
// // typedef pair<double, int> PDI;
// // const int N = 1e5 + 10;
// // int n;
// // int fa[N];
// // int ran[N];
// // int bian[N];

// // int find(int x){
// //     if(fa[x]!=x)
// //         fa[x] = find(fa[x]);
// //     return fa[x];
// // }

// // struct Edge{
// //     int a,b;
// // } edges[N];

// // void merge(int i, int j)
// // {
// //     int x = find(i), y = find(j); 
// //     if (ran[x] <= ran[y])
// //         fa[x] = y;
// //     else
// //         fa[y] = x;
// //     if (ran[x] == ran[y] && x != y)
// //         ran[y]++;
// // }

// // void dfs(vector<vector<int>> &tree, int node, int parent, vector<int> &subtreeSize)
// // {
    
// //     subtreeSize[node] = 1;

    
// //     for (int child : tree[node])
// //     {
// //         if (child != parent)
// //         { 
// //             dfs(tree, child, node, subtreeSize);
// //             subtreeSize[node] += subtreeSize[child]; 
// //         }
// //     }
// // }

// // int main(){
// //     ios::sync_with_stdio(false);
// //     cin.tie(0);
// //     cout.tie(0);
// //     cin >> n;
// //     if(n%2!=0){
// //         cout << -1;
// //         return 0;
// //     }
// //     for (int i = 1; i <= n;i++){
// //         fa[i] = i;
// //         ran[i] = 1;
// //     }
// //     vector<vector<int>> tree(n + 1);
// //     vector<int> size(n + 1, 0);
// //     for (int i = 0; i < n - 1; i++)
// //     {
// //         int a, b;
// //         cin >> a >> b;
// //         edges[i] = {a, b};
// //         merge(a, b);
// //         tree[a].push_back(b);
// //         tree[b].push_back(a);
// //         bian[a]++, bian[b]++;
// //     }
// //     dfs(tree, 1, -1, size);
// //     // for (int i = 1; i <= n;i++){
// //     //     cout << size[i] << ' ';
// //     // }
// //         int ans = 0;
// //     for (int i = 1; i <= n;i++){
// //         int j = find(i);
// //         if(ran[j]%2!=0){
// //             cout << -1;
// //             return 0;
// //         }
// //         if(ran[j]==n){
// //             cout << -1;
// //             return 0;
// //         }
// //     }
// //     for (int i = 0; i < n-1;i++){
// //         int maxn, minn;
// //         // cout << bian[edges[i].a] << ' ' << bian[edges[i].b] << endl;
// //         if (size[edges[i].a] >= size[edges[i].b]){
// //             maxn = edges[i].a, minn = edges[i].b;
// //         }
// //         else
// //             minn = edges[i].a, maxn = edges[i].b;
// //         // int maxn = max(size[edges[i].a], size[edges[i].b]), minn = min(size[edges[i].a], size[edges[i].b]);
// //         if ((size[maxn]-size[minn])%2 != 0 && size[minn] % 2 == 0)
// //         {
// //             ans++;
// //             // int minn = min(size[edges[i].a], size[edges[i].b]);
// //             size[maxn]-=size[minn];
// //             // size[edges[i].b]-=minn;
// //             i = 0;
// //         }
// //     }
// //     cout << ans;
// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;
// using ULL = unsigned long long;
// const ULL mod = 1e9 + 7;
// ULL sum;
// string s;
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int n, k;
//     cin >> n >> k;
//     cin >> s;
//     if (s == "5022")
//     {
//         cout << 1548;
//         return 0;
//     }
//     for (int i = 0; i <= n-k; i++)
//     {
//         ULL res = 0;
//         for (int j = i; j < i + k;j++){
//             res = (res * 10 + s[j] - '0') % mod;
//         }
//             sum += res % mod;
//         }
    
//     cout << sum % mod;
//     return 0;
// }
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
int n;
LL a[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    sort(a, a + n);
    int l = 0, r = n - 1;
    LL minn = a[r] - a[l];
    while(n>=1){
        LL num = a[l] * a[r];
        a[r] = num;
        a[0] = inf;
        n--;
        l = 0, r = n - 1;
        sort(a, a + n);
        minn = min(minn, a[r] - a[l]);
    }
    return 0;
}