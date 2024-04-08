#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 25;
int a[N]={1};
int n;

void dfs(int x,int sum){
    for (int i = a[x-1]; i <=sum;i++){
        if(i<n){
            a[x] = i;
            sum -= i;
            if (sum == 0){
                for (int j = 1; j < x; j++){
                    cout << a[j] << '+';
                }
                cout << a[x] << endl;
            }
            else
                dfs(x + 1, sum);
            sum += i;
        }
    }
    // return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    dfs(1, n);
    return 0;
}