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
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        if(s.size()<=2){
            cout << "NO\n";
            continue;
        }
        if(s[0]!='1' || s[1]!='0'){
            cout << "NO\n";
            continue;
        }
        if(s[2]=='0'){
            cout << "NO\n";
            continue;
        }
        else if(s[0]=='1' && s[1]=='0'){
            if((s[2]=='1' ||s[2]=='0') && s.size()==3){
                cout << "NO\n";
            }
            else
                cout << "YES\n";
        }
    }
    return 0;
}