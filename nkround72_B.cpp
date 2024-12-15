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
#include <bitset>
#include <climits>
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
#define lnf LLONG_MAX
#define endl '\n'
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const double pi = acos(-1);
const int N = 2e5 + 10;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    string s;
    cin >> s;
    LL cnt = 0;
    LL t = 1;
    for(int i = 1; i < s.size(); i++){
        if(s[i] != s[i-1]){
            t++;
        }
        else{
            if(t >= 2){
                cnt += (t * (t -1))/2;
            }
            t = 1;
        }
    }
    if(t >=2){
        cnt += (t * (t -1))/2;
    }
    cout << cnt << endl;
    return 0;
}
