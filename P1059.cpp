#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<unordered_map>
using namespace std;
using LL = long long;
using ULL=unsigned long long;
vector<int> v;
const int N = 105;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << v.size() << endl;
    ;
    for (int i = 0; i < v.size();i++){
        cout << v[i] << ' ';
    }
        return 0;
}