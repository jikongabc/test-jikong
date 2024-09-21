#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int N;
    cin >> N;                 // 读取建筑数量
    vector<int> heights(N);   // 存储建筑的高度
    vector<int> result(N, 0); // 存储每个建筑的结果
    stack<int> stk;           // 栈，用来存储建筑的索引

    // 读取每个建筑的高度
    for (int i = 0; i < N; i++)
    {
        cin >> heights[i];
    }

    // 从左向右遍历每一个建筑
    for (int i = 0; i < N; i++)
    {
        // 如果当前建筑高度大于栈顶的建筑高度，说明栈顶建筑被遮挡，移除栈顶元素
        while (!stk.empty() && heights[i] > heights[stk.top()])
        {
            result[stk.top()] = i - stk.top() - 1; // 计算满足条件的建筑数量
            stk.pop();
        }
        // 将当前建筑压入栈中
        stk.push(i);
    }

    // 处理栈中剩下的建筑，它们后面没有更高的建筑
    while (!stk.empty())
    {
        result[stk.top()] = N - stk.top() - 1;
        stk.pop();
    }

    // 输出结果
    for (int i = 0; i < N; i++)
    {
        cout << result[i] << (i == N - 1 ? "\n" : " ");
    }

    return 0;
}
