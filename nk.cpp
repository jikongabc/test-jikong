#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int n;
int a[N];
int cnt[N];
int ans1[N], ans2[N];
bool cnt1[N], cnt2[N];
// set<int> s1;
// set<int> s2;
string s1,s2;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        s1 += i + '0';
        s2 += i + '0';
    }
    // s1.erase(0,1);
    cout << s1 << endl;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[a[i]]++;
        if (cnt[a[i]] > 2){
            cout << -1;
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (cnt[a[i]] <= 1){
            ans1[i] = a[i];
            // cnt1[a[i]] = 1;
            s1.erase(a[i]-1, 1);
            // s1.insert(a[i]);
        }
        else{
            ans2[i] = a[i];
            // cnt2[a[i]] = 1;
            s2.erase(a[i]-1,1);
            // s2.insert(a[i]);
        }
    }
        cout << s1 << endl;
        // int temp;
        for (int i = 1; i <= n; i++)
        {
            // temp = 1;
            if (ans1[i] == 0)
            {
                cout << s1[0] << ' ';
                s1.erase(0, 1);
                // for (int j = 1; j <= n;j++){
                //     if(!cnt1[j]){
                //         cnt1[j] = 1;
                //         cout << j << ' ';
                //         break;
                //     }
                // }
                // while (s1.find(temp) != s1.end())
                // {
                //     temp++;
                // }
                // cout << temp << ' ';
                // s1.insert(temp);
            }
            else
                cout << ans1[i] << ' ';
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        // temp = 1;
        if (ans2[i] == 0)
        {
            cout << s2[0] << ' ';
            s2.erase(0, 1);
            // for (int j = 1; j <= n; j++){
            //     if (!cnt2[j]){
            //         cnt2[j] = 1;
            //         cout << j << ' ';
            //         break;
            //     }
            // }
            // while (s2.find(temp) != s2.end())
            // {
            //     temp++;
            // }
            // cout << temp << ' ';
            // s2.insert(temp);
        }
        else
            cout << ans2[i] << ' ';
    }
    return 0;
}