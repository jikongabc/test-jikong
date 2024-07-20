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
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
int n;
int y[N];
int tr[N];
LL V, A;
LL lower[N], heigher[N];

int lowbit(int x){
    return x & -x;
}

void add(int x,int c){
    for (int i = x; i <= n;i+=lowbit(i))
        tr[i] += c;
}

LL sum(int x){
    LL res = 0;
    for (int i = x; i;i-=lowbit(i))
        res += tr[i];
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> y[i];
    for (int i = 1; i <= n;i++){
        int t = y[i];
        lower[i] = sum(t - 1);
        heigher[i] = sum(n) - sum(t);
        add(t, 1);
    }
    memset(tr, 0, sizeof tr);
    for (int i = n; i >= 1; i--){
        int t = y[i];
        lower[i] *= sum(t - 1);
        A += lower[i];
        heigher[i] *= sum(n) - sum(t);
        V += heigher[i];
        add(t, 1);
    }
    cout << V << ' ' << A << endl;
    return 0;
}
