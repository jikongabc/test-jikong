// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <vector>
// #include <map>
// #include <queue>
// #include <deque>
// #include <set>
// #include <unordered_map>
// #include <string>
// using namespace std;
// // using LL = long long;
// // using ULL = unsigned long long;
// typedef long long LL;
// const int N = 105;
// int n, k;
// LL a;
// LL ans;
// int p[N];
// priority_queue<LL, vector<LL>, greater<LL>> q;
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> k;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> p[i];
//         q.push(p[i]);
//     }
//     int cnt = 0;
//     while (!q.empty() && cnt < k)
//     {
//         a = q.top();
//         q.pop();
//         if (a == ans)
//             continue;
//         cnt++;
//         int t = n;
//         if(cnt>k/2){
//             t = min(n, 5);
//         }
//         ans = a;
//         for (int i = 1; i <= t; i++)
//         {
//             q.push(a * p[i]);
//         }
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
#include <string>
using namespace std;
typedef long long LL;
const int N = 105;
int n, k;
LL a;
LL ans;
int p[N];
priority_queue<LL, vector<LL>, greater<LL>> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> p[i];
        q.push(p[i]);
    }
    int cnt = 0;
    set<LL> visited;
    while (!q.empty() && cnt < k){
        a = q.top();
        q.pop();
        if (visited.find(a) != visited.end()) 
            continue;
        visited.insert(a); 
        cnt++;
        int t = n;
        if(cnt>k/2){
            t = min(n, 5);
        }
        ans = a;
        for (int i = 1; i <= t; i++){
            q.push(a * p[i]);
        }
    }
    cout << ans;
    return 0;
}