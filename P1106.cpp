#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <string>
#include <list>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 255;
int a[N];
string s;
int k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    cin >> k;
    int l = s.size();
    for (int i = 0; i < l;i++){
        a[i] = s[i] - '0';
    }
    for (int i = 0; i < k;i++){
        for (int j = 0; j < l;j++){
            if(a[j]>a[j+1]){
                for (int m = j; m < l;m++){
                    a[m] = a[m + 1];
                }
                l--;
                break;
            }
        }
    }
    int cnt = 0;
    if(l==1 && a[0]==0){
        cout << 0;
        return 0;
    }
    while(!a[cnt]){
        cnt++;
    }
    for (int i=cnt; i < l;i++){
        cout << a[i];
    }

        return 0;
}