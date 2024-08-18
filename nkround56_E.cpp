#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int n, m;
PII times[N];
unordered_set<string> se; //奶茶种类

// 时间 -> 数
int to_minute(const string &time){
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    return h * 60 + m;
}

// 检查某个时间点是否在给定的时间范围内
bool pd(int time){
    int l = 0, r = n - 1;
    while (l < r){
        int mid = l + r >> 1;
        if (times[mid].first <= time && time <= times[mid].second){
            return true;
        }
        else if (time < times[mid].first)
            r = mid;
        else
            l = mid + 1;
    }
    return times[l].first <= time && time <= times[l].second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        string start, end;
        cin >> start >> end;
        times[i] = {to_minute(start), to_minute(end)};
    }

    sort(times, times + n);
    for (int i = 0; i < m; i++){
        string tea;
        cin >> tea;
        se.insert(tea); 
    }
    int T;
    cin >> T;
    while (T--){
        string a, b, c, tea;
        cin >> a >> b >> c >> tea;
        int ta = to_minute(a);
        int tb = to_minute(b);
        int tc = to_minute(c);
        bool flag1 = (ta >= to_minute("00:00") && ta <= to_minute("01:59") && pd(ta));
        bool flag2 = se.count(tea) > 0; 
        if (flag1){
            if (tb <= tc){
                if (flag2){
                    cout << "Winner xqq" << endl; // 邀请成功，没离开
                }
                else{
                    cout << "Joker xqq" << endl; // 邀请成功，奶茶不对，中途离开
                }
            }
            else{
                cout << "Joker xqq" << endl; // 邀请成功，迟到，中途离开
            }
        }
        else{
            cout << "Loser xqq" << endl; // 邀请失败，没达成成就
        }
    }
    return 0;
}
