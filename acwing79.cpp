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
typedef pair<double, int> PDI;
typedef pair<int, string> PIS;
typedef pair<int, PII> PIII;
const int N = 1e5 + 10;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
string step = "urdl";
string start;
string seq;
string end1 = "12345678x";

int f(string state)
{
    int res = 0;

    for (int i = 0; i < state.size(); i++)
    {
        if (state[i] != 'x')
        {
            int t = state[i] - '1';
            res += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
        }
    }
    return res;
}

string bfs(string start)
{
    unordered_map<string, int> dist;
    unordered_map<string, pair<string, char>> pre;
    priority_queue<PIS, vector<PIS>, greater<PIS>> q;
    q.push({f(start), start});
    dist[start] = 0;
    while (q.size())
    {
        auto t = q.top();
        q.pop();
        string state = t.second;
        if (state == end1)
            break;
        int temp = dist[state];
        int x, y;
        for (int i = 0; i < state.size(); i++)
        {
            if (state[i] == 'x')
            {
                x = i / 3, y = i % 3;
                break;
            }
        }
        string source = state;
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || b < 0 || a >= 3 || b >= 3)
                continue;
            swap(state[x * 3 + y], state[a * 3 + b]);
            if (!dist.count(state) || dist[state] > temp + 1)
            {
                dist[state] = temp + 1;
                pre[state] = {source, step[i]};
                q.push({dist[state] + f(state), state});
            }
            swap(state[x * 3 + y], state[a * 3 + b]);
        }
    }
    string res;
    while (end1 != start)
    {
        res += pre[end1].second;
        end1 = pre[end1].first;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char ch;
    while (cin >> ch)
    {
        start += ch;
        if (ch != 'x')
            seq += ch;
    }
    int cnt = 0;
    for (int i = 0; i < seq.size(); i++)
    {
        for (int j = i + 1; j < seq.size(); j++)
        {
            if (seq[i] > seq[j])
                cnt++;
        }
    }
    if (cnt % 2)
        cout << "unsolvable\n";
    else
        cout << bfs(start) << endl;

    return 0;
}
