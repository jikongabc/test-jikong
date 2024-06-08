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
int sum;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 5;i++){
        int x;
        cin >> x;
        sum += x;
    }
    if(sum>100)
        cout << "YES";
    else
        cout << "NO";
        return 0;
}