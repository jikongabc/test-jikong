#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 1e5 + 10;
int q;
int pd, x, y;
int head, idx, e[N], ne[N];

void init(){
    head = -1;
    idx = 0;
}

void add_to_head(int x){
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

void add(int k,int x){
    // e[idx] = x;
    // ne[idx] = ne[k];
    // ne[k] = idx++;
    ne[x] = ne[k];
    ne[k] = x;
}

void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cin >> q;
    while(q--){
        cin >> pd;
        if(pd==1){
            cin >> x >> y;
            add(x, y);
        }
        if(pd==2){
            cin >> x;
            cout << ne[x] << '\n';
        }
        if(pd==3){
            cin >> x;
            remove(x);
        }
    }
    return 0;
}