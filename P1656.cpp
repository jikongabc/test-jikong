#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<unordered_map>
#define intf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
const int N = 5005;
int n, m;
int fa[N];

struct node{
    int a, b;
    bool flag;
} p[N];

bool cmp(node x,node y){
    if(x.a==y.a)
        return x.b < y.b;
    return x.a < y.a;
}

int find(int x){
    if(fa[x]!=x)
        fa[x] = find(fa[x]);
    return fa[x];
}

bool solve(){
    int cnt = 0;
    for (int i = 1; i <= n;i++)
        fa[i] = i;
    for (int i = 0; i < m; i++){
        if(p[i].flag)
            continue;
        int a = find(p[i].a), b = find(p[i].b);
        if(a!=b){
            fa[a] = b;
        }
    }
    for (int i = 1; i <= n;i++){
        if(fa[i]==i)
            cnt++;
    }
    return cnt > 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m;i++){
        int a, b;
        cin >> a >> b;
        if(a>b){
            int temp = b;
            b = a,a = temp;
        }
        p[i] = {a, b, false};
    }
    sort(p, p + m, cmp);
    for (int i = 0; i <m;i++){
        p[i].flag = true;
        if(solve())
            cout << p[i].a << ' ' << p[i].b << endl;
        p[i].flag = false;
    }
    return 0;
}