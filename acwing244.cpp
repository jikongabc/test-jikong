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
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int n;
int a[N];
int res[N];
int tr[N];

int lowbit(int x){
    return x & -x;
}

void add(int x,int c){
    for (int i = x; i <= n;i+=lowbit(i))
        tr[i] += c;
}

int sum(int x){
    int res = 0;
    for (int i = x; i;i-=lowbit(i))
        res += tr[i];
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 2; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= n;i++)
        add(i, 1);
    for (int i = n; i;i--){
        int k = a[i] + 1;
        int l = 1, r = n;
        while(l<r){
            int mid = l + r >> 1;
            if(sum(mid)>=k)
                r = mid;
            else
                l = mid + 1;
        }
        res[i] = r;
        add(r, -1);
    }
    for (int i = 1; i <= n;i++)
        cout << res[i] << endl;
    return 0;   
}