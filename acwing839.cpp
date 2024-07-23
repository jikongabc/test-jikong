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
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1e5 + 10;
int h[N],ph[N],hp[N],cnt;
int n, m;

void heap_swap(int a,int b){
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u){
    int t = u;
    if(u*2<=cnt && h[u*2]<h[t])
        t = u * 2;
    if(u*2+1<=cnt && h[u*2+1]<h[t])
        t = u * 2 + 1;
    if(u!=t){
        heap_swap(u, t);
        down(t);
    }
}

void up(int u){
    while(u/2 && h[u]<h[u/2]){
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while(n--){
        string op;
        int k, x;
        cin >> op;
        if(op=="I"){
            cin >> x;
            cnt++;
            m++;
            ph[m] = cnt, hp[cnt] = m;
            h[cnt] = x;
            up(cnt);
        }
        else if(op=="PM")
            cout << h[1] << endl;
        else if(op=="DM"){
            heap_swap(1, cnt);
            cnt--;
            down(1);
        }
        else if(op=="D"){
            cin >> k;
            k = ph[k];
            heap_swap(k, cnt);
            cnt--;
            up(k);
            down(k);
        }
        else{
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            up(k);
            down(k);
        }

    }
    return 0;
}