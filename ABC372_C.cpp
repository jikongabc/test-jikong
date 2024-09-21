#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    int abc_count = 0;

    // 先统计整个字符串中 "ABC" 出现的次数
    for (int i = 0; i <= n - 3; i++)
    {
        if (s.substr(i, 3) == "ABC")
        {
            abc_count++;
        }
    }

    // 处理每个查询
    while (q--)
    {
        int x;
        char c;
        cin >> x >> c;
        x--; // 将1-based索引转换为0-based索引

        // 检查修改之前的 "ABC" 子串是否存在，减少计数
        for (int i = max(0, x - 2); i <= min(n - 3, x); i++)
        {
            if (s.substr(i, 3) == "ABC")
            {
                abc_count--;
            }
        }

        // 更新字符串
        s[x] = c;

        // 检查修改之后的 "ABC" 子串是否存在，增加计数
        for (int i = max(0, x - 2); i <= min(n - 3, x); i++)
        {
            if (s.substr(i, 3) == "ABC")
            {
                abc_count++;
            }
        }

        // 输出当前的 "ABC" 出现次数
        cout << abc_count << endl;
    }

    return 0;
}
