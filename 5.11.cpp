#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
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
typedef pair<double, int> PDI;
const int N = 2e5 + 10;
set<char> s1;
set<char> s2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    s1.insert('a'), s1.insert('e');
    s2.insert('b'), s2.insert('c'), s2.insert('d');
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s2.find(s[i]) != s2.end() && s1.find(s[i + 1]) != s1.end() && s2.find(s[i + 2]) != s2.end() && s1.find(s[i + 3]) != s1.end() && i < s.size() - 2)
            {   
                    cout << s[i] << s[i + 1] << '.';
                    i++;
            
            }
            else if (s2.find(s[i]) != s2.end() && s1.find(s[i + 1]) != s1.end() && s2.find(s[i + 2]) != s2.end() && s2.find(s[i + 3]) != s2.end() &&i < s.size() - 3)
            {
                    cout << s[i] << s[i + 1] << s[i + 2] << '.';
                    i += 2;
                
            }
            else
                cout << s[i];
        }
        cout << endl;
    }
    return 0;
}