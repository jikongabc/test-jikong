#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;
const int N = 2e5 + 10;
int n, m;
string s;
unordered_map<char, char> ma;
struct node{
    int id;
    char a, b;
} p[N];


// unordered_map<char, char> fa;
// int find(int x){
//     if(fa[x]==x)
//         return x;
//     else
//         return find(fa[x]);
// }
// void merge(int a,int b){
//     fa[find(a)] = find(b);
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> s;
    cin >> m;
    char ch1, ch2;
    for (int i = 'a'; i <= 'z'; i++){
        ma[i] = i;
    }
    for (int i = 0; i < m;i++){
        cin >> ch1 >> ch2;
        p[i].a = ch1, p[i].b = ch2;
        p[i].id = i;
        // ma[ch1] = ch2;
    }
    for (int i = m - 1; i >= 0;i--){
        ma[p[i].a] = ma[p[i].b];
    }
        for (int i = 0; i < s.size(); i++)
        {
            cout << ma[s[i]];
        }
        return 0;
}