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
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1e5 + 10;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char c1, c2, c3;
    cin >> c1 >> c2 >> c3;
    if (c1 == '<' && c2 == '>' || c1 == '>' && c2 == '<')
        cout << "A\n";
    else if (c1 == '<' && c3 == '<' || c1 == '>' && c3 == '>')
        cout << "B\n";
    else
        cout << "C\n";
    return 0;
}