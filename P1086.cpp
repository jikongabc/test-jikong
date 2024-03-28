#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;
using LL = long long;
typedef pair<int, int> PII;
const int N = 25;
int p[N][N];
bool st[N][N];
int n, m, k;
int ans = 0;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
// queue<PII> q;
// queue<PII> q1;
struct node{
    PII a;
    int cnt;
} op[N * N];

bool cmp(const node&a,const node&b){
    return a.cnt > b.cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    int num = 0;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> p[i][j];
            if(p[i][j]){
                op[num].a = {i, j};
                op[num].cnt = p[i][j];
                num++;
            }
        }
    }
    sort(op, op + num, cmp);
    if (2*op[0].a.first+1 > k){
        cout<<0;
        return 0;
    }
    else{
        k -= op[0].a.first;
        k--;
        ans += op[0].cnt;
    }
    auto temp = op[0].a;
    for (int i = 1; i < num;i++){
        int oo = abs(op[i].a.first - temp.first) + abs(op[i].a.second - temp.second) + 1;
        if(k-oo-op[i].a.first>=0){
            k -= oo;
            temp = op[i].a;
            ans += op[i].cnt;
        }
        else {
            break;
        }
    }
    cout << ans;
    return 0;
}