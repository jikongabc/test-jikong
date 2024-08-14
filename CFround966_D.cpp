#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<long long> prefix_sum(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        prefix_sum[i + 1] = prefix_sum[i] + a[i];
    }

    string s;
    cin >> s;

    long long result = 0;

    int left = 0, right = n - 1;
    while (left < right)
    {
        while (left < right && s[left] != 'L')
            left++;
        while (left < right && s[right] != 'R')
            right--;
        if (left < right)
        {
            result += prefix_sum[right + 1] - prefix_sum[left];
            left++;
            right--;
        }
    }

    cout << result << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
