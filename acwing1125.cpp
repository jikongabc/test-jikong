#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

using PII = pair<int, int>;
const int N = 155;
const double inf = numeric_limits<double>::infinity();
int n;
PII q[N];
char g[N][N];
double d[N][N];
double maxd[N];

double get_dist(PII i, PII j)
{
    return sqrt((i.first - j.first) * (i.first - j.first) + (i.second - j.second) * (i.second - j.second));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i].first >> q[i].second;

    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (g[i][j] == '1')
                    d[i][j] = get_dist(q[i], q[j]);
                else
                    d[i][j] = inf;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (d[i][j] < inf)
                maxd[i] = max(maxd[i], d[i][j]);
        }
    }

    double res1 = 0;
    for (int i = 0; i < n; i++)
        res1 = max(res1, maxd[i]);

    double res2 = inf;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (d[i][j] == inf)
                res2 = min(res2, maxd[i] + maxd[j] + get_dist(q[i], q[j]));
        }
    }

    printf("%.6lf", max(res1, res2));
    return 0;
}
