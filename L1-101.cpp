#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <unordered_map>
#include <string>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 105;
int n, k;
string s[N];
string ss;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> s[i];
    cin>>k;
    if(!k){
        cout << 0 << endl << "He Xie Ni Quan Jia!";
        return 0;
    }
    cin.ignore();
    int cnt = 0;
    getline(cin, ss);
    for (int i = 0; i < n;i++){
        while(ss.find(s[i])!=-1){
            int t = ss.find(s[i]);
            cnt++;
            ss.erase(t, s[i].size());
            ss.insert(t, "<censored>");
        }
    }
    if(cnt>=k)
        cout << cnt << endl << "He Xie Ni Quan Jia!";
    // else{
    //     while(ss.find("@_@")!=-1){
    //         int t = ss.find("@_@");
    //         ss.erase(t, 3);
    //         ss.insert(t, "<censored>");
    //     }
    //     cout << ss;
    // } 
    else
        cout << ss;
    return 0;
}