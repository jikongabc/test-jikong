#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

struct Node
{
    ll total_r, total_e, total_d;
    ll total_re, total_ed, total_red;
};

int n, q;
string s, t;
vector<Node> seg_s, seg_t;

void build(vector<Node> &seg, const string &str, int v, int tl, int tr)
{
    if (tl == tr)
    {
        seg[v].total_r = (str[tl] == 'r');
        seg[v].total_e = (str[tl] == 'e');
        seg[v].total_d = (str[tl] == 'd');
        seg[v].total_re = 0;
        seg[v].total_ed = 0;
        seg[v].total_red = 0;
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(seg, str, v * 2, tl, tm);
        build(seg, str, v * 2 + 1, tm + 1, tr);
        Node &left = seg[v * 2];
        Node &right = seg[v * 2 + 1];
        seg[v].total_r = left.total_r + right.total_r;
        seg[v].total_e = left.total_e + right.total_e;
        seg[v].total_d = left.total_d + right.total_d;
        seg[v].total_re = left.total_re + left.total_r * right.total_e + right.total_re;
        seg[v].total_ed = left.total_ed + left.total_e * right.total_d + right.total_ed;
        seg[v].total_red = left.total_red + left.total_re * right.total_d + left.total_r * right.total_ed + right.total_red;
    }
}

void update(vector<Node> &seg, int v, int tl, int tr, int pos, char c)
{
    if (tl == tr)
    {
        seg[v].total_r = (c == 'r');
        seg[v].total_e = (c == 'e');
        seg[v].total_d = (c == 'd');
        seg[v].total_re = 0;
        seg[v].total_ed = 0;
        seg[v].total_red = 0;
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(seg, v * 2, tl, tm, pos, c);
        else
            update(seg, v * 2 + 1, tm + 1, tr, pos, c);
        Node &left = seg[v * 2];
        Node &right = seg[v * 2 + 1];
        seg[v].total_r = left.total_r + right.total_r;
        seg[v].total_e = left.total_e + right.total_e;
        seg[v].total_d = left.total_d + right.total_d;
        seg[v].total_re = left.total_re + left.total_r * right.total_e + right.total_re;
        seg[v].total_ed = left.total_ed + left.total_e * right.total_d + right.total_ed;
        seg[v].total_red = left.total_red + left.total_re * right.total_d + left.total_r * right.total_ed + right.total_red;
    }
}

ll get_total_red(const vector<Node> &seg)
{
    return seg[1].total_red;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    cin >> s >> t;
    s = " " + s; // 1-based indexing
    t = " " + t;

    int size = 4 * n;
    seg_s.resize(size);
    seg_t.resize(size);
    build(seg_s, s, 1, 1, n);
    build(seg_t, t, 1, 1, n);

    for (int i = 0; i < q; ++i)
    {
        int x;
        cin >> x;
        // Swap s[x] and t[x]
        char old_s = s[x];
        char old_t = t[x];
        s[x] = old_t;
        t[x] = old_s;
        update(seg_s, 1, 1, n, x, s[x]);
        update(seg_t, 1, 1, n, x, t[x]);
        ll total_red_s = get_total_red(seg_s);
        ll total_red_t = get_total_red(seg_t);
        cout << total_red_s - total_red_t << '\n';
    }

    return 0;
}
