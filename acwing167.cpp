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
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 70;
int n;
int w[N];
bool st[N];
int sum, len;

bool dfs(int u,int lenth,int start){
    if(u*len==sum)
        return true;
    if(lenth==len)
        return dfs(u + 1, 0, 0);
    for (int i = start; i < n;i++){
        if(st[i] || lenth+w[i]>len)
            continue;
        st[i] = 1;
        if(dfs(u,lenth+w[i],i+1))
            return true;
        st[i] = 0;
        if(!lenth || lenth+w[i]==len)
            return false;
        int j = i;
        while(j<n && w[j]==w[i])
            j++;
        i = j - 1;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n , n){
        memset(st, 0, sizeof st);
        sum = 0;
        for (int i = 0; i < n;i++){
            cin >> w[i];
            sum += w[i];
        }
        sort(w, w + n);
        reverse(w, w + n);
        len = 1;
        while(true){
            if(sum%len==0 && dfs(0,0,0)){
                cout << len << endl;
                break;
            }
            len++;
        }
    }
    return 0;
}