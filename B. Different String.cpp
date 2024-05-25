#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
typedef pair<PII, int> PIII;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> s;
        bool pd = 0;
        int flag;
        int n = s.size();
        for (int i = 0; i < n-1;i++){
            if(s[i]!=s[i+1]){
                pd = 1;
                flag = i;
            }
        }
        if(!pd){
            cout << "NO\n";
            continue;
        }
        else{
            cout << "YES\n";
            swap(s[flag], s[flag + 1]);
            cout << s << endl;
        }
    }
    return 0;
}