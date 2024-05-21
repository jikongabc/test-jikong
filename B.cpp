#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
int n;
string s;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        cin >> s;
        set<char> ss;
        for (int i = 0; i < n;i++){
            ss.insert(s[i]);
        }
        string s2 = "";
        for(auto ch:ss){
            s2 += ch;
        }
        // cout << s2 << endl;
        int m = s2.size();
        unordered_map<char, char> ma;
        for (int i = 0; i < m;i++){
            ma[s2[i]] = s2[m -1- i];
        }
        // for (int i = 0; i < m;i++){
        //     cout << s2[i] << ' ' << ma[s2[i]] << endl;
        // }
            for (int i = 0; i < n;i++){
                cout << ma[s[i]];
            }
            cout << endl;
    }
    return 0;
}