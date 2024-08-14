#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        set<int> occupied;
        bool valid = true;

        for (int i = 0; i < n; ++i)
        {
            int seat = a[i];
            if (i == 0)
            {
                occupied.insert(seat);
                continue;
            }

            if (occupied.count(seat - 1) || occupied.count(seat + 1))
            {
                occupied.insert(seat);
            }
            else
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
