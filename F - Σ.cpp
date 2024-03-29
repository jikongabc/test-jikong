#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
using LL =unsigned long long;
LL n, k;
set<LL> s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    LL sum = 0;
    for (LL i = 0; i < n;i++){
        LL num;
        cin >> num;
        if(num<=k && s.find(num)==s.end())
            sum += num;
            s.insert(num);
    }
    
    LL ans=((1+k) *k)/2-sum;
    cout << ans;
    return 0;
}