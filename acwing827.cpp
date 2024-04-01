#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 1e5 + 10;
int e[N], r[N], l[N], idx;

void init(){
    r[0] = 1;
    l[0] = 0;
    idx = 2;
}

void add_to_right(int k,int x){
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx++;
}

void add_to_left(int k,int x){
    add_to_right(l[k], x);
}
void remove(int k){
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

void add_to_head(int x){
    add_to_right(0, x);
}

void add_to_tail(int x){
    add_to_right(l[1], x);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    init();
    cin >> m;
    while(m--){
        string s;
        cin >> s;
        if(s=="L"){
            int x;
            cin >> x;
            add_to_head(x);
        }
        else if(s=="R"){
            int x;
            cin >> x;
            add_to_tail(x);
        }
        else if(s=="D"){
            int k;
            cin >> k;
            remove(k + 1);
        }
        else if(s=="IL"){
            int k, x;
            cin >> k >> x;
            add_to_left(k + 1, x);
        }
        else{
            int k, x;
            cin >> k >> x;
            add_to_right(k + 1, x);
        }
    }    
    for (int i = r[0]; i != 1;i=r[i]){
        cout << e[i] << ' ';
    }
    
        return 0;
}
