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
#define endl '\n'
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 10;
double a[N];

int main(){
	// ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	for(int i = 0; i < 5; i++){
		cin >> a[i];
	}
	double p = a[3] + a[4];
	double q = 1 - p;
	double p0 = pow(q, 10);
	double p1 = 10 * p * pow(q, 9);
	double res = 1 - (p0 + p1);
	printf("%.10lf", res);
	return 0;
}