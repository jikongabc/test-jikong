#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 1e4+10;
int p;
int a, b;
int temp;
void dfs(int x,int y,int cnt){
    if(temp)
        return;
    if(cnt>20000){
        cout << "error\n";
        return;
    } 
    // else{
    //     cout << "error\n";
    //     return;
    // }
    if(!x && y){
        cout << "1\n";
        temp = 1;
    }
    else if(x && !y){
        cout << "2\n";
        temp = 1;
    }
    else{
        if ((cnt + 1) % 2)
            dfs((x + y) % p, y, cnt + 1);
        else
            dfs(x, (x + y) % p, cnt + 1);
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t >> p;
    while(t--){
        temp = 0;
        cin >> a >> b;
        dfs(a, b, 0);
    }

    return 0;
}