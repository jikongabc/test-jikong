#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<double, int> PDI;
const int N = 1e5 + 10;
int n;
int a[N];
unordered_map<int, int> ma;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        ma[a[i]]++;
    }
    int res = 0;
    int cnt = 0, cnt1 = 0;
    for(auto i:ma){
        if(i.second==1){
            cnt++;
        }
        if(i.second>2){
            cnt1 += i.second - 2;
        }
        if(cnt1>cnt){
            res += cnt;
            cnt1 -= cnt;
            cnt = 0;
        }
        else{
            res += cnt1;    
            cnt -= cnt1;
            cnt1 = 0;
        }

    }
    cout << res + cnt1 + cnt / 2;
    return 0;
}