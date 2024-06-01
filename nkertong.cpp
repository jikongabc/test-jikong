#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
typedef pair<PII, int> PIII;
string s;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    n = s.size();
    LL a = 0, b = 0, c = 0;
    for (int i = 0; i < n;i++){
        if(s[i]=='7')
            a++;
        if(s[i]=='6')
            b += a;
        if(s[i]=='1')
            c += b;
    }
    cout << c;
    return 0;   
}