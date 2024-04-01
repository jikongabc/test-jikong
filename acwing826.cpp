#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 1e5 + 10;
int head, e[N], ne[N], idx;

void init(){
    head = -1;
    idx = 0;
}

void add_to_head(int x){
    e[idx] = x, ne[idx] = head, head = idx++;
}

void add(int k,int x){
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}

void remove(int k){
    ne[k] = ne[ne[k]];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> m;
    char c;
    int k, x;
    init();
    while(m--){
        cin >> c;
        if(c=='H'){
            cin >> x;
            add_to_head(x);
        }
        else if(c=='D'){
            cin >> k;
            if(!k)
                head = ne[head];
           else
               remove(k - 1);
        }
        else{
            cin >> k >> x;
            add(k-1, x);
        }
    }
    for (int i = head; i != -1;i=ne[i])
        cout << e[i] << ' ';
        return 0;
}