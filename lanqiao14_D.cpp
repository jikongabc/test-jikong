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
#include <cmath>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<double, int> PDI;
const int N = 1e5 + 10;
int n, m;
int a[N], b[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    deque<int> a, b;
    for (int i = 0; i < n;i++){
        int num;
        cin >> num;
        a.push_back(num);
    }
    for (int i = 0; i < m;i++){
        int num;
        cin >> num;
        b.push_back(num);
    }
    int cnt = 0;
    while(!a.empty() && !b.empty()){
        if(a.front()==b.front()){
            a.pop_front();
            b.pop_front();
        }
        else if(a.front()<b.front()){
            int x = a.front();
            a.pop_front();
            int y = a.front();
            a.pop_front();
            a.push_front(x + y);
            cnt++;
        }
        else if(a.front()>b.front()){
            int x = b.front();
            b.pop_front();
            int y = b.front();
            b.pop_front();
            b.push_front(x + y);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}