#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 505;
int n, m, k;
vector<int> a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> k;
        for (int j = 1; j <= k;j++){
            int num;
            cin >> num;
            a[i].push_back(num);
        }
    }
    int q;
    cin >> q;
    while(q--){
        int res = 0;
        int u, v;
        cin >> u >> v;
        for (int i = 1; i <= n;i++){
            int cnt = 0;
            for(auto c:a[i]) 
                if(c==u||c==v)
                    cnt++;
            if(cnt==2)
                res++;
        }
        cout << res << endl;
    }
    return 0;
}

