#include<iostream>
#include<sstream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<double, int> PDI;
const int N = 1e6 + 10;
string s;
int n;
LL a, b, c, d;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i <= 2023;i++){
        s += to_string(i);
    }
        // cout << s;
    int n = s.size();
    // cout << n;
    for (int i = 0; i < n;i++){
        if(s[i]=='2'){
            a++;
            c += b;
        }
        if(s[i]=='0'){
            b += a;
        }
        if(s[i]=='3'){
            d += c;
        }
    }
    cout << d;

    return 0;
}