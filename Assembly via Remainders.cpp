#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
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
typedef pair<double, int> PDI;
const int N = 1005;
int x[N], a[N];
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for (int i = 1; i < n;i++){
            cin >> x[i];
        }
        a[0] = 99999;
        for (int i = 1; i < n;i++){
            a[i] = a[i - 1] + x[i];
        }
        for (int i = 0; i < n;i++){
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}