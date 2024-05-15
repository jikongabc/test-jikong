#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
int n;
const int dx[] = {1, 1, -1, 1, -1, -1, 1, -1};
const int dy[] = {1, 1, 1, -1, 1, -1, -1, -1};
const int dz[] = {1, -1, 1, 1, -1, 1, -1, -1};
LL a[N][3];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0);
    cin >> n;
    LL ans = 0;
    for (int i = 0; i < n;i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    for (int i = 0; i < 8;i++){
        LL sum = 0;
        int xx = dx[i], yy = dy[i], zz = dz[i];
        for (int j = 0; j < n;j++){
            int res = 0;
            int x = a[j][0], y = a[j][1], z = a[j][2];
            if(x<0 && xx<0|| x>0 && xx>0)
                res += abs(x);
            else
                res -= abs(x);
            if(y<0 && yy<0|| y>0 && yy>0)
                res += abs(y);
            else
                res -= abs(y);
            if(z<0 && zz<0|| z>0 && zz>0)
                res += abs(z);
            else
                res -= abs(z);
            if(res>0)
                sum += res;
        }
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}