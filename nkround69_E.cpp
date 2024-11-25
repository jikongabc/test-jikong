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
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const int N = 2e5 + 10;
int n;
int a[N];
LL pre[N];
LL cnt[N];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	LL res = 0;
	LL sum = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
		sum += a[i];
		if(a[i] > 0 ) cnt[i] = cnt[i - 1] + 1;
		else cnt[i] = cnt[i - 1];
	}
	if(sum % 3 != 0){
		cout << 0 << endl;
		return 0;
	}
	if(n <= 2000){
		// for(int i = 1; i <= n; i++) cout << cnt[i] << ' ';
		// cout << endl;
	for(int i = 1; i < n; i++){
		for(int j = i + 1; j <= n; j++){
			LL sum1 = pre[i] - pre[0];
			LL sum2 = pre[j] - pre[i];
			LL sum3 = pre[n] - pre[j];
			if(sum1 != sum2 || sum2 != sum3 || sum3 != sum1) continue;
			// bool flag1 = false, flag2 = false, flag3 = false;
			// for(int k = 1; k <= i; k++){
			// 	if(a[k] > 0){
			// 		flag1 = true;
			// 		break;
			// 	}
			// }
			// for(int k = i + 1; k <= j; k++){
			// 	if(a[k] > 0){
			// 		flag2 = true;
			// 		break;
			// 	} 
			// }
			// for(int k = j + 1; k <= n; k++){
			// 	if(a[k] > 0){
			// 		flag3 = true;
			// 		break;
			// 	}
			// }
			int cnt1 = cnt[i] - cnt[0];
			int cnt2 = cnt[j] - cnt[i];
			int cnt3 = cnt[n] - cnt[j];
			if(cnt1 > 0 && cnt2 > 0 && cnt3 > 0) res++;
		}

		
	}
	cout << res;
	return 0;
	}
	LL s = sum / 3;
	vector<int> v1, v2;
	for(int i = 1; i <= n; i++){
		if(pre[i] == s && cnt[i] > 0) v1.push_back(i);
		if(pre[i] == 2 * s && cnt[n] - cnt[i] > 0) v2.push_back(i);
	}
	sort(v2.begin(), v2.end());
	for(int i = 0; i < v1.size(); i++){
		int pos = v1[i];
		int l = 0, r = v2.size(), idx = -1;
		while(l < r){
			int mid = l + r >> 1;
			if(v2[mid] > pos){
				idx = mid;
				r = mid;
			}
			else l = mid + 1;
		}
		if(idx != -1) res += v2.size() - idx;	
	}
	cout << res;
	return 0;
}