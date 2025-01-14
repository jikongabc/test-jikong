// #include <iostream>
// #include <algorithm>
// #define endl '\n'
// using namespace std;
// int main(){
// 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
// 	string a, b;
// 	cin >> a >> b;
// 	int n = a.size(), m = b.size();
// 	a += a;
// 	b += b;
// 	int maxn = 0;
// 	for(int i = 0; i < n;i++){
// 		for(int j = 0; j < m ;j++){
// 			int k = 0;
// 			while(a[i + k] == b[j + k] && k < m && k < n){
// 				k++;
// 			}
// 			maxn = max(maxn, k);
// 		}		
// 	}
// 	cout << maxn << endl;
// 	return 0;
// }



#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string a, b;
	cin >> a >> b;
	int n = a.size(), m = b.size();
	int maxn = 0;
	for(int i = 0; i < n;i++){
		for(int j = 0; j < m ;j++){
			int k = 0;
			while(a[(i + k) % n] == b[(j + k) % m] && k < m && k < n){
				k++;
			}
			maxn = max(maxn, k);
		}		
	}
	cout << maxn << endl;
	return 0;
}