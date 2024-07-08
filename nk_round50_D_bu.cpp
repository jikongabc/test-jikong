#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath> 
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
int a, b, c;
int res_a1, res_a2, res_b1, res_b2;

vector<int>get_divisors(int x){
    vector<int> res;
    for (int i = 1; i <= sqrt(abs(x));i++){
        if(x%i==0){
            res.push_back(i);
            res.push_back(-i);
            if(i!=x/i){
                res.push_back(x / i);
                res.push_back(-x / i);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

bool find(int a,int b,int c){
    vector<int> v = get_divisors(a);
    vector<int> vv = get_divisors(c);
    for(int a1:v){
        int a2 = a / a1;
        for(int b1:vv){
            int b2 = c / b1;
            if(a1*b2+b1*a2==b){
                res_a1 = a1, res_a2 = a2, res_b1 = b1, res_b2 = b2;
                return true;
            }
        }
    }
    return false;
}

bool find1(int a,int b){
    vector<int> v = get_divisors(a);
    for(int a1:v){
        int a2 = a / a1;
        int b1 = b / a2;
        if(b1*a2==b){
            res_a1 = a1, res_a2 = a2, res_b1 = b1, res_b2 = 0;
            return true;
        }
    }
    return false;
}

void solve(){
    cin >> a >> b >> c;
    if (b && c)
    {
        if (find(a, b, c))
        {
            cout << res_a1 << ' ' << res_b1 << ' ' << res_a2 << ' ' << res_b2 << endl;
        }
        else
            cout << "NO" << endl;
    }
    else if(!b && !c){
        cout << 1 << ' ' << 0 << ' ' << a << 0 << endl;
    }
    else if(b && !c){
        if(find1(a,b)){
            cout << res_a1 << ' ' << res_b1 << ' ' << res_a2 << ' ' << res_b2 << endl;
        }
        else
            cout << "NO" << endl;
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
