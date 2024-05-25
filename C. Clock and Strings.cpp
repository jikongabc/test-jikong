#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
typedef pair<PII, int> PIII;
int a, b, c, d;
int u[] = {1, 2, 3, 4, 4, 5, 6, 7, 8, 9, 10, 11, 12};
bool check(int a,int b,int c,int d){
    bool pd1, pd2;
    if(a>b)
        swap(a, b);
    for (int i = a + 1; i < b; i++)
    {
        if(i==c)
            pd1 = 0;
        if(i==d)
            pd2 = 0;
    }
    a += 12;
    for (int i = b + 1; i < a;i++){
        int temp = i;
        if(temp>12)
            temp -= 12;
        if(temp==c)
            pd1 = 1;
        if(temp==d)
            pd2 = 1;
    }
    if(pd1==1 && pd2==1 || pd1==0 && pd2==0){
        return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> a >> b >> c >> d;
        if(check(a,b,c,d))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}