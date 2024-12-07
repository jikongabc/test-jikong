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
// const int N =  ;
int n;
int cnt;
int res[505][505];
int pos[505];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
    int x = 1;
    
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            res[i][pos[i]++] = x;
            res[j][pos[j]++] = x;
            x++;
        }
    }
    
    for(int i = 0; i < n; i++){
        res[i][n-1] = x++;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
	return 0;
}