#include<iostream>
using namespace std;
int main(){
	int x1, y1, x2, y2;
	int res = 0;
	cin >> x1 >> y1 >> x2 >> y2;
	if(x1 == 0 && y1 == 0 || x2 == 0 && y2 == 0){
		cout << 1;
		return 0;
	}
	if((double)y1 / x1 == (double)y2 / x2 && x1 * x2 <= 0 && y1 * y2 <= 0){
		cout << 1;
		return 0;
	}
	if(x1 * x2 <= 0) res++;
	if(y1 * y2 <= 0) res++;
	cout << res;
	return 0;
}