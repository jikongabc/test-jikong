#include <iostream>
#define endl '\n'
using namespace std;
int main(){
	string s[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	int n;
	cin >> n;
	if(n < 0){
		cout << "fu ";
		n = -n;
	} 
	string t = "";
	while(n){
		t = s[n % 10] + ' ' + t;
		n /= 10;
	}
	cout << t;
	return 0;
}