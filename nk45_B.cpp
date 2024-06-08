#include <iostream>
#include <sstream>
#include <vector>
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
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int n, m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    if(n==1){
        cout << "NO";
        return 0;
    }
    if(m==1){
        cout << "YES";
        return 0;
    }
    if(n%2==0  || m%2!=0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}