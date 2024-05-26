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
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
typedef pair<PII, int> PIII;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> a >> b;
    if(a==b){
        cout << "-1";
        return 0;
    }
    int cnt[4];
    cnt[a]++, cnt[b]++;
    for (int i = 1; i <= 3;i++){
        if(cnt[i]==0)
            cout << i;
    }
        return 0;
}