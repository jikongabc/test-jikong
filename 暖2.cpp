#include<iostream>
using namespace std;
int main(){
	int n, m, a;
	cin >> n >> m >> a;
	cout << (long long)(n / a) * (m / a);
	return 0;
}