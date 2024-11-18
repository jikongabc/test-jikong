#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
    int n;
    cin >> n;
    set<int> se1, se2;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        se1.insert(x);
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        se2.insert(x);
    }
    int cnt = 0;
    for(auto i : se1){
        if(se2.count(i)) cnt++;
    }
    int sz1 = se1.size() - cnt, sz2 = se2.size() - cnt;
    if(sz1 > sz2) swap(sz1,sz2);
    if(cnt <= sz2 - sz1){
        sz1 += cnt;
        cout << n - min(sz1, sz2);
    }
    else{
        cnt -= (sz2 - sz1);
        cout << n - sz2 - cnt / 2;
    }
    return 0;    
}