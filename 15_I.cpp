#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int n;
int a[N];
const int price[8] = {0, 7, 27, 41, 49, 63, 78, 108};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n;i++){
            cin >> a[i];
            sum += price[a[i]];
        }
        if(sum>=120)
            sum -= 50;
        else if(sum>=89)
            sum -= 30;
        else if(sum>=69)
            sum -= 15;
        cout << sum << endl;
    }
    return 0;
}