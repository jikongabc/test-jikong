#include<stdio.h>
#include<string.h>
char s[100005], t[100005];
int mp[26], rmp[26];
int main(){
	int n;
	scanf("%d", &n);
	getchar();
	gets(s);
	for(int i = n - 1; i >= 0; i --){
		scanf("%c", &t[i]);
	}
	for(int i = 0; i < n; i ++){
		if(mp[s[i] - 'a'] == 0 && rmp[t[i] - 'a'] == 0){
			mp[s[i] - 'a'] = t[i];
			rmp[t[i] - 'a'] = 1;
		}
		else if(mp[s[i] - 'a'] != t[i]){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}