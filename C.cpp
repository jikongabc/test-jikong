#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 3e5 + 10;
LL a[N];
int n;

LL beautifulTripletsCount(LL a[], int n)
{
    LL cnt = 0;
    unordered_map<string, LL> ma1;
    unordered_map<string, LL> ma2;
    unordered_map<string, LL> ma3;
    unordered_map<string, LL> ma4;
    for (int i = 0; i <= n-3;i++){
        string s = to_string(a[i]) + to_string(a[i + 1]) + to_string(a[i + 2]);
        ma1[s]++;

        s = to_string(a[i]) + to_string(a[i + 1]);
        ma2[s]++;
        s = to_string(a[i]) + to_string(a[i + 2]);
        ma3[s]++;
        s = to_string(a[i+1]) + to_string(a[i + 2]);
        ma4[s]++;
    }
    // for (auto it = ma1.begin(); it != ma1.end();it++){
    //     cout << it->first << ' ' << it->second << endl;
    // }
        // string start = to_string(a[0]) + to_string(a[1]), end1 = to_string(a[n - 2]) + to_string(a[n - 1]);
        // ma2[end1]++;
    for (int i = 0; i <= n - 3;i++)
    {
        string s = to_string(a[i]) + to_string(a[i + 1]) + to_string(a[i + 2]);
        string ss = "";
        ss += s[0];
        ss += s[1];
        // if(ss==temp)
        //     ma2[ss]++;
        cnt += (ma2[ss] - ma1[s]);
        // ma2[ss]--;
        // if(end1==ss)
        //     cnt--;
        ss = "";
        ss += s[1];
        ss += s[2];
        cnt += (ma4[ss] - ma1[s]);
        // ma4[ss]--;
        // temp = ss;
        // if(start==ss)
        //     cnt--;
        ss = "";
        ss += s[0];
        ss += s[2];
        cnt += (ma3[ss] - ma1[s]);
        // ma3[ss]--;
        // ma1[s]--;
        }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for (int i = 0; i < n;i++){
            cin >> a[i];
        }
        cout << beautifulTripletsCount(a, n) << endl;
    }
    return 0;
}