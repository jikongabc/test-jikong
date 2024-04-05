#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 5e3+10;

struct heng{
    int cnt1;
    int id1;
} p1[N];
struct shu{
    int cnt2;
    int id2;
} p2[N];

bool cmp1(heng a,heng b){
    return a.cnt1 > b.cnt1;
}
bool cmp2(shu a,shu b){
    return a.cnt2 > b.cnt2;
}
set<int> s1;
set<int> s2;
int heng[N], shu[N];
int n, m, k, l, d;
int x1, y1, x2, y2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k >> l >> d;
    for (int i = 0; i < d;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1==x2){
            p2[min(y1, y2)].cnt2++;
            // shu[min(y1, y2)]++;
            p2[min(y1, y2)].id2 = min(y1, y2);
        } 
        else{
            p1[min(x1, x2)].cnt1++;
            // heng[min(x1, x2)]++;
            p1[min(x1, x2)].id1 = min(x1, x2);
        }
    }
    sort(p1, p1 + n, cmp1);
    sort(p2, p2 + m, cmp2);
    int temp = 0;
    while(k){
        if(!p1[temp].id1)
            break;
        // cout << p1[temp].id1 << ' ';
        s1.insert(p1[temp].id1);
        k--;
        temp++;
    }
    // cout << endl;
    temp = 0;

    while (l)
    {
        if (!p2[temp].id2)
            break;
        // cout << p2[temp].id2 << ' ';
        s2.insert(p2[temp].id2);
        l--;
        temp++;
    }
    for (int i = 1; i < n;i++){
        if(!k)
            break;
        if(s1.find(i)==s1.end()){
            s1.insert(i);
            k--;
        }
    }
    for (int i = 1; i < m;i++){
        if(!l)
            break;
        if(s2.find(i)==s2.end()){
            s2.insert(i);
            l--;
        }
    }
    for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
        cout << *it << " ";
    cout << endl;
    for (set<int>::iterator it = s2.begin(); it != s2.end(); it++)
        cout << *it << " ";

    return 0;
}