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
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 205;
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    double x1, y1, x2, y2;
    cin >> x1 >> y1;
    double sum = 0;
    while(cin>>x1>>y1>>x2>>y2){
        double dx = x1 - x2, dy = y1 - y2;
        sum += sqrt(dx * dx + dy * dy) * 2;
    }
    int minutes = round(sum / 1000 / 20 * 60);
    int hours = minutes / 60;
    minutes %= 60;
    printf("%d %02d\n", hours, minutes);
    return 0;
}