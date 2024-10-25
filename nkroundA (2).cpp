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
const int N =  ;


int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int x;
    cin >> x;
    cout << x << endl;

    vector<PII> results;

    int max_b = 20; 

    for (int b = 1; b <= max_b; ++b) {
        double a_approx = pow(x, 1.0 / b);
        int a_start = max(2, (int)(a_approx) - 2);
        int a_end = (int)(a_approx) + 2;
        for (int a = a_start; a <= a_end; ++a) {
            if (a >= 2) {
                double power = pow(a, b);
                if (abs(power - x) < 1e-6) {
                    results.push_back({b, a});
                    break; 
                }
            }
        }
    }

    sort(results.begin(), results.end());

    for (auto &p : results) {
        cout << "=" << p.second << "^" << p.first << endl;
    }
    return 0;
}