#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int N=25;
int n;
string words[N];
int cnt[N];
int st[N][N];
int ans=0;
char start;
void dfs(string dragon,int x){
	ans=max(ans,(int)dragon.size());
	cnt[x]++;
	for(int i=0;i<n;i++){
		if(st[x][i] && cnt[i]<2){
			dfs(dragon+words[i].substr(st[x][i]),i);
		}
	}
	cnt[x]--;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>words[i];
	}
	cin>>start;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			string a=words[i],b=words[j];
			for(int k=1;k<min(a.size(),b.size());k++){
				if(a.substr(a.size()-k,k)==b.substr(0,k)){
					st[i][j]=k;
					break;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		if(words[i][0]==start){
			dfs(words[i],i);
		}
	}
	cout<<ans;
	return 0;
}
