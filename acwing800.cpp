#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N];
int n, m, x;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> x;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    for (int i = 0; i < m;i++)
        cin >> b[i];
    for (int i = 0, j = m - 1; i < n;i++){
        while(a[i]+b[j]>x && j>=0){
            j--;
        }
        if(a[i]+b[j]==x){
            cout << i << ' ' << j;
            break;
        }
    }
    return 0;
}