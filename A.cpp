#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int x, y;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> y >> x;
        // if(x==0 && y==0){
        //     cout << 0 << endl;
        //     continue;
        // }
        int cnt = 0;
        if(x==0 && y!=0){
            if(y%15==0)
                cout << y / 15 << endl;
            else
                cout << y / 15 + 1 << endl;
            continue;
        }
        if(x!=0 && y==0){
            if(x%2==0)
                cout << x / 2 << endl;
            else
                cout << x / 2 + 1 << endl;
            continue;
        }
        while(x>0 || y>0){
            if(x>=2){
                x -= 2;
                y -= 7;
            }
            else{
                y -= (15 - (x * 4));
                x = 0;
            }
            cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}