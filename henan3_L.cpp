#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1e5 + 10;
unordered_map<string, string> pub_lic;
unordered_map<string, unordered_map<string, unordered_set<string>>> hosts;
int m, n, q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n >> q;
    for (int i = 0; i < m; i++){
        string pub, pri;
        cin >> pub >> pri;
        pub_lic[pri] = pub;
    }
    for (int i = 0; i < n; ++i)
    {
        string ip;
        int k;
        cin >> ip >> k;
        unordered_map<string, unordered_set<string>> users;
        for (int j = 0; j < k; ++j)
        {
            string user;
            int t;
            cin >> user >> t;
            unordered_set<string> public_keys;
            for (int l = 0; l < t; l++)
            {
                string pub;
                cin >> pub;
                public_keys.insert(pub);
            }
            users[user] = public_keys;
        }
        hosts[ip] = users;
    }
    while(q--)
    {
        string user, ip, pri;
        cin >> user >> ip >> pri;
        if (pub_lic.find(pri) == pub_lic.end())
        {
            cout << "No" << endl;
            continue;
        }

        string pub = pub_lic[pri];
        if (hosts.find(ip) != hosts.end() &&
            hosts[ip].find(user) != hosts[ip].end() &&
            hosts[ip][user].find(pub) != hosts[ip][user].end())
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}
