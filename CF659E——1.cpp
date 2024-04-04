// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <vector>
// #include <map>
// #include <queue>
// #include <deque>
// #include <set>
// #include <unordered_map>
// using namespace std;
// using LL = long long;
// using ULL = unsigned long long;
// const int N = 1e5 + 10;
// int n, m;
// int fa[N];
// bool vis[N];

// // void init(int n){
// //     for (int i = 1; i <= n; i++){
// //         fa[i] = i;
// //     }
// // }

// int find(int x){
//     if (fa[x] != x)
//         return fa[x] = find(fa[x]);
//     else
//         return fa[x];
// }

// // void merge(int i, int j){
// //     fa[find(i)] = find(j);
// // }

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> m;
//     // init(n);
//     for (int i = 1; i <= n;i++){
//         fa[i] = i;
//     }
//         while(m--){
//             int a, b;
//             cin >> a >> b;
//             int aa = find(a), bb = find(b);
//             if (aa == bb){
//                 vis[aa] = vis[bb] = vis[a] = vis[b] = true;
//             }
//             // merge(a, b);
//             else{
//                 fa[aa] = bb;
//                 if (vis[aa] || vis[bb] || vis[a] || vis[b])
//                     vis[bb] = vis[aa] = vis[a] = vis[b] = true;
//             }
//     }
//     int ans = 0;
//     for (int i = 1; i <= n; i++){
//         if (find(i) == i && !vis[i])
//             ans++;
//     }
//     cout << ans;
//     return 0;
// }

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
const int N = 1e5 + 10;
int n, m;
int a, b;
int fa[N];
int ans;
int temp;
bool vis[N];

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
}

int find(int x)
{
    if (fa[x] == x)
        return fa[x];
        else fa[x] = find(fa[x]);
        return fa[x];
}

// void merge(int i, int j){
//     fa[find(i)] = find(j);
// }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        int aa = find(a), bb = find(b);
        if (aa == bb)
        {
            vis[aa] = 1;
        }
        else
        {
            // merge(a, b);
            fa[aa] = bb;
            if (vis[aa] || vis[bb])
                vis[bb] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (fa[i] == i && !vis[i])
            ans++;
    }
    cout << ans;
    return 0;
}