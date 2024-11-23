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
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n * 3;i++){
        for (int j = 0; j < n;j++)
            cout << '*';
        for (int j = 0; j < 2 * n;j++)
            cout << '.';
        for (int j = 0; j < n; j++)
            cout << '*';
        cout << endl;
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= i;j++){
            cout << '.';
        }
        for (int j = 1; j <= n;j++){
            cout << '*';
        }
        for (int j = 1; j <= 2 * (n - i);j++)
            cout << '.';
        for (int j = 1; j <= n; j++){
            cout << '*';
        }
        for (int j = 1; j <= i; j++)
        {
            cout << '.';
        }
        cout << endl;
    }

        return 0;
}