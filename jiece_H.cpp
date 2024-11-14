#include<stdio.h>
double add[1010]; //存加法项
int is_mul[1010]; //标记是否为乘法项，1表示乘法，0表示加法
double mul[1010][1010]; // 存储每个乘法表达式的因子
int mul_cnt[1010]; // 存储每个乘法表达式的因子数量
int count; // 表达式的计数

void sort(double a[], int n){ // 冒泡排序
	for(int i = 0; i < n - 1; i ++){
		for(int j = 0; j < n - i - 1; j ++){
			if(a[j] > a[j + 1]){
				double t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}

}	

// 对所有表达式按结果值排序，同时调整乘法标记和因子数组顺序
void sort1(){
	for(int i = 0; i < count - 1; i ++){
		for(int j = 0; j < count - i - 1; j ++){
			if(add[j] > add[j + 1]){
				//交换值
				double t = add[j];
				add[j] = add[j + 1];
				add[j + 1] = t;
				//交换乘法印记
				int t1 = is_mul[j];
				is_mul[j] = is_mul[j + 1];
				is_mul[j + 1] = t1;
				//交换因子数组
				double t_mul[1010];
				int t_cnt = mul_cnt[j];
				for(int k = 0; k < mul_cnt[j]; k ++){
					t_mul[k] = mul[j][k];
				}
				mul_cnt[j] = mul_cnt[j + 1];
				for(int k = 0; k < mul_cnt[j + 1]; k ++){
					mul[j][k] = mul[j + 1][k];
				}
				mul_cnt[j + 1] = t_cnt;
				for(int k = 0; k < t_cnt; k ++){
					mul[j + 1][k] = t_mul[k];
				}
			}
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	char c;
	double t;
	int cnt = 0;
	while(cnt < n){
		scanf("%lf%c", &t, &c);
		cnt ++;
		if(c == '*'){ // 当前是乘法表达式
		    add[count] = t;
		    is_mul[count] = 1;
		    mul[count][0] = t;
		    int pos = 1;
		    while(c == '*' && cnt < n){ // 读取乘法部分的因子
		    	scanf("%lf%c", &t, &c);
		    	cnt ++;
		    	add[count] *= t;
		    	mul[count][pos ++] = t;
		    }
		    mul_cnt[count] = pos; // 设置当前乘法表达式的因子数量
		    sort(mul[count], mul_cnt[count]); // 对当前乘法表达式的因子排序
		    count ++;
		}
		else{ // 当前是加法表达式
			add[count] = t;
			is_mul[count] = 0;
			mul_cnt[count] = 1; // 单个数值的加法项只有一个因子
			mul[count][0] = t;
			count ++;
		}
	}
	sort1(); // 对所有表达式排序
	for(int i = 0; i < count; i ++){  // 输出结果
		if(i > 0) printf("+");
		if(is_mul[i]){ // 输出乘法表达式
			for(int j = 0; j < mul_cnt[i]; j ++){
				if(j > 0) printf("*");
				printf("%.2lf", mul[i][j]);
			}
		}
		else printf("%.2lf", add[i]);  // 输出单个加法项
	}
	return 0;
}