// // 1
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdio>
// #include <queue>
// #include <deque>
// #include <vector>
// #include <map>
// #include <set>
// #include <unordered_map>
// #include <string>
// using namespace std;
// int dfs(int x){
//     if(x==1)
//         return 1;
//     else if(x==2)
//         return 2;
//     else
//         return dfs(x - 1) + dfs(x - 2);
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int n;
//     cin >> n;
//     int ans = dfs(n);
//     cout << ans;
//     return 0;
// }
// // 2
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdio>
// #include <queue>
// #include <deque>
// #include <vector>
// #include <map>
// #include <set>
// #include <unordered_map>
// #include <string>
// using namespace std;
// const int N = 100;
// int mem[N];
// int dfs(int x)
// {   if(mem[x])
//         return mem[x];
//     int sum = 0;
//     if (x == 1)
//         sum = 1;
//     else if (x == 2)
//         sum = 2;
//     else
//         sum= dfs(x - 1) + dfs(x - 2);
//     mem[x] = sum;
//     return sum;
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int n;
//     cin >> n;
//     int ans = dfs(n);
//     cout << ans;
//     return 0;
// }
// // 3
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdio>
// #include <queue>
// #include <deque>
// #include <vector>
// #include <map>
// #include <set>
// #include <unordered_map>
// #include <string>
// using namespace std;
// const int N = 100;
// int mem[N];
// int f[N];
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int n;
//     cin >> n;
//     f[1] = 1, f[2] = 2;
//     for (int i = 3; i <= n;i++){
//         f[i] = f[i - 1] + f[i - 2];
//     }
//         cout << f[n];
//     return 0;
// }
// 4
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;
const int N = 100;
int mem[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if(n==1)
        cout << 1;
    else if(n==2)
        cout << 2;
    else{
        int newf = 0, temp1 = 1, temp2 = 2;
        for (int i = 3; i <= n; i++)
        {
            newf = temp1 + temp2;
            temp1 = temp2;
            temp2 = newf;
        }
        cout << newf;
    }
    
    return 0;
}