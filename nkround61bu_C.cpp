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
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int fact[N], infact[N];
int n, x, y;
string s;
unordered_map<char, int> id;
int cnt[5];

int qmi(int a, int k, int p){
    int res = 1;
    while (k){
        if (k & 1)
            res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

void init(){
    fact[0] = infact[0] = 1;
    id['U'] = 2, id['R'] = 1, id['D'] = 0, id['L'] = 3;
    for (int i = 1; i < N; i++){
        fact[i] = (LL)fact[i - 1] * i % mod;
        infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
}

int C(int a,int b){
    return (LL)fact[a] * infact[b] % mod * infact[a - b] % mod;
}

void solve(){
    memset(cnt, 0, sizeof cnt);
    cin >> n >> x >> y;
    cin >> s;
    for (int i = 0; i < n;i++)
        cnt[id[s[i]]]++;
    int cntx = cnt[2] - cnt[0];//下减上
    int cnty = cnt[1] - cnt[3];//右减左
    int tx = cntx - x;
    int ty = cnty - y;
    int ttx = abs(tx), tty = abs(ty);
    int posx = 0, posy = 0;
    int rposx = 0, rposy = 0;
    if(tx>0){
        if(cnt[2]>=tx){
            posx = 2;
            rposx = 0;
        }
        else{
            cout << "NO\n";
            return;
        }
    
    }
    if(tx<0){
        if(cnt[0]>=abs(tx)){
            posx = 0;
            rposx = 2;
        }
        else{
            cout << "NO\n";
            return;
        }
    }
    if(ty>0){
        if(cnt[1]>=ty){
            posy = 1;
            rposy = 3;
        }
        else{
            cout << "NO\n";
            return;
        }
    }
    if(ty<0){
        if(cnt[3]>=abs(ty)){
            posy = 3;
            rposy = 1;
        }
        else{
            cout << "NO\n";
            return;
        }
    }
    cout << "YES ";
    for (int i = 0; i < n; i++){
        if (id[s[i]] ==posx  && ttx > 0){
            ttx--;
            continue;
        }
        if (id[s[i]] ==posy  && tty > 0){
            tty--;
            continue;
        }
        cout << s[i];
    }
    int resx = 0, resy = 0;
    int cx = cnt[posx] - abs(tx);
    int cy = cnt[posy] - abs(ty);
    for (int i = 0; i <= min(cnt[rposx], cx); i++){
        resx = (resx + C(cnt[posx], abs(tx) + i) * C(cnt[rposx], i)) % mod;
    }
    for (int i = 0; i <= min(cnt[rposy], cy); i++){
        resy = (resy + C(cnt[posy], abs(ty) + i) * C(cnt[rposy], i)) % mod;
    }
    cout <<' ' << (resx * resy) % mod;
    cout << endl;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    init();
    while(T--){
        solve();
    }
    return 0;
}