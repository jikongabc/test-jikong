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
unordered_map<int, int> ma;
int q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        if(x==1){
            int a;
            cin >> a;
            ma[a]++;
        }
        else if(x==2){
            int a;
            cin >> a;
            ma[a]--;
            if(ma[a]==0)
                ma.erase(a);
        }
        else if(x==3){
            cout << ma.size() << endl;
        }
    }
    return 0;
}
