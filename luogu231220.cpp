//#include <iostream>
//#include <cstdio>
//using namespace std;
//int main() {
//	int n;
//	cin >> n;
//	float ans = 0, maxNum = -1, minNum = 100;
//	int p = n;
//	while (n--) {
//		float x;
//		cin >> x;
//		ans += x;
//        // 记录最大值和最小值，最后再减去这两个值
//		maxNum = max(x, maxNum), minNum = min(x, minNum);
//	}
//	printf("%.2f", (ans - maxNum - minNum) / (p - 2.0));
//	return 0;
//}

#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,k,p;//10^12>2^31-1
	cin>>n>>k;
	if(n%2==1){
		p = n/2+1;//奇数数量 = 偶数数量+1
	}
	else{
		p = n/2;//奇数数量 = 偶数数量
	}
	if(k>p){
		cout<<(k-p)*2<<endl;
	}
	else{
		cout<<2*k-1<<endl;
	}
}
