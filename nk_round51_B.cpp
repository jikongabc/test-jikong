#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    LL sum = 0;
    while(n--){
        string x;
        cin >> x;
        for (int i = 0; i < x.size();i++){
            sum += x[i] - '0';
        }
    }
    cout << sum;
    if(sum%3==0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
