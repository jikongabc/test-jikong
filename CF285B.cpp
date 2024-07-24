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
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
map<string, string> ma;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while(n--){
        string s1, s2;
        cin >> s1 >> s2;
        if(ma.count(s1)==0){
            ma[s2] = s1;
        }
        else{
            ma[s2] = ma[s1];
            ma.erase(s1);
        }
    }
    cout << ma.size() << endl;
    for(auto [a,b]:ma){
        cout << b << ' ' << a << endl;
    }
    return 0;   
}