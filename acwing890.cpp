#include<iostream>
#include<algorithm>
using namespace std;
using LL = long long;
const int N = 20;
int p[N];
int n, m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m;i++)
        cin >> p[i];
    int res = 0;
    for (int i = 1; i < 1 << m;i++){
        int t = 1, s = 0;
        for (int j = 0; j < m;j++){
            if(i>>j &1){
                if((LL) t*p[j]>n){
                    t = -1;
                    break;
                }
                t *= p[j];
                s++;
            }
        }
        if (t != -1){
            if (s % 2)
                res += n / t;
            else
                res -= n / t;
        }
    }
    cout << res;
    return 0;
}