#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 1005;
vector<LL> num;
vector<LL>::iterator it;
int a, b, c, d;
char ch[3];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c >> d;
    num.push_back(a);
    num.push_back(b);
    num.push_back(c);
    num.push_back(d);
    cin >> ch[0] >> ch[1] >> ch[2];
    if (ch[0] == '*' && ch[1]=='*' && ch[2]=='+'){
        sort(num.begin(), num.end());
        cout << (LL)num[0] * num[3] + num[1] * num[2];
        return 0;
    }
    else if (ch[0] == '*' && ch[1] == '+' && ch[2] == '*'){
        sort(num.begin(), num.end());
        cout << (LL)(num[1] * num[2] + num[3]) * num[0];
        return 0;
    }
        for (int i = 0; i < 3; i++)
        {
            if (ch[i] == '+')
            {
                sort(num.begin(), num.end());
                LL temp = num[num.size() - 1] + num[num.size() - 2];
                num.pop_back();
                num.pop_back();
                num.push_back(temp);
            }
            else{
            sort(num.begin(), num.end(), greater<int>());
            LL temp = num[num.size() - 1] * num[num.size() - 2];
            num.pop_back();
            num.pop_back();
            num.push_back(temp);
        }

    }
    cout << num[0];

    return 0;
}
