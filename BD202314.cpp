#include<iostream>
#include<sstream>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<deque>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
typedef pair<PII, int> PIII;
const int N = 1e5 + 10;
int n;

struct Cat{
    int p, v;
} cats[N];

bool cmp(Cat a,Cat b){
    if(a.p==b.p)
        return a.v < b.v;
    return a.p < b.p;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n;i++){
        int p, v;
        cin >> p >> v;
        cats[i] = {p, v};
    }
    sort(cats, cats + n, cmp);
    for (int i = 0; i < n-1;i++){
        if(cats[i].p==cats[i+1].p)
            cats[i + 1].v = cats[i].v;
    }
    int res = 0;
    int cnt = 1;
    int idx = n - 1;
    while(1){
        if(idx-cnt<0)
            break;
        if((cats[idx].p!=cats[idx-cnt].p && cats[idx].v<cats[idx-cnt].v) || (cats[idx].p==cats[idx-cnt].p))
            cnt++;
        else{
            idx = idx - cnt;
            cnt = 1;
        }
        res = max(res, cnt);
    }
    cout << res;
    return 0;
}