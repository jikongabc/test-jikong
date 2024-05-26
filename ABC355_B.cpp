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
const int N = 1000;
int n, m;
int a[N], b[N];
vector<int> c;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        c.push_back(a[i]);
    }
    for (int i = 0; i < m;i++){
        cin >> b[i];
        c.push_back(b[i]);
    }
    sort(c.begin(), c.end());
    for (int i = 0; i < c.size()-1;i++){
        for (int j = 0; j < n-1;j++){
            if(c[i]==a[j] && c[i+1]==a[j+1] || c[i]==a[j+1] && c[i+1]==a[j]){
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}