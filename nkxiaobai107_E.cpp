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
#include <bitset>
#include <climits>
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
#define lnf LLONG_MAX
#define endl '\n'
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const double pi = acos(-1);
const int N = 100005;
LL a[N];

struct Node{
    LL a;
    int d;
} p[N];

int n;

bool cmp(const Node &x, const Node &y){
    return x.a < y.a;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> p[i].d;
    for (int i = 0; i < n; i++)
        p[i].a = a[i];
    sort(p, p + n, cmp);
    int parent = 0;
    LL sum = 0;
    for (int i = 1; i < n; i++){
        while (parent < i && p[parent].d <= 0){
            parent++;
        }
        sum += p[parent].a;
        p[parent].d--;
    }
    cout << sum;
}
