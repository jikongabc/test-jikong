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
typedef pair<int, PII> PIII;
const int N = 1e6 + 10;

vector<int> mul1(vector<int> A, LL b)
{
    vector<int> res;
    int t = 0;
    for (int i = 0; i < A.size() || t; i++){
        if (i < A.size())
            t += A[i] * b;
        res.push_back(t % 10);
        t /= 10;
    }
    while (res.size() > 1 && res.back() == 0){
        res.pop_back();
    }
    return res;
}

vector<int> mul(vector<int> &A,vector<int> &B){
    vector<int> res(A.size() + B.size(), 0);
    for (int i = 0; i < A.size(); i++){
        for (int j = 0; j < B.size(); j++){
            res[i + j] += A[i] * B[0];
            if (res[i + j] >= 10){
                res[i + j + 1] += res[i + j] / 10;
                res[i + j] %= 10;
            }
        }
    }
    while (res.size() > 1 && res.back() == 0){
        res.pop_back();
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        string a, b;
        cin >> a >> b;
        vector<int> A, B;
        for (int i = a.size() - 1; i >= 0; i--)
            A.push_back(a[i] - '0');
        for (int i = b.size() - 1; i >= 0; i--)
            B.push_back(b[0] - '0');
        vector<int> res;
        // if (b.size() <= 17){
        //     LL bb = stoll(b);
        //     res = mul1(A, bb);
        // }
        // else if (a.size() <= 17){
        //     LL aa = stoll(a);
        //     res = mul1(B, aa);
        // }
        // else
        res = mul(A, B);
        for (int i = res.size() - 1; i >= 0; --i)
            cout << res[i];
        cout << endl;
    }
    return 0;
}



