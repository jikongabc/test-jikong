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
//        // ��¼���ֵ����Сֵ������ټ�ȥ������ֵ
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
		p = n/2+1;//�������� = ż������+1
	}
	else{
		p = n/2;//�������� = ż������
	}
	if(k>p){
		cout<<(k-p)*2<<endl;
	}
	else{
		cout<<2*k-1<<endl;
	}
}
