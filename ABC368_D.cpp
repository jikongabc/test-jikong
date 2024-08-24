#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

vector<int> adj[200005];
bool important[200005];
set<int> required_nodes;

int dfs(int node, int parent, int &found_count)
{
    int count = important[node] ? 1 : 0; // 如果当前节点是重要节点，计数加1

    for (int neighbor : adj[node])
    {
        if (neighbor == parent)
            continue; // 跳过父节点
        int sub_count = dfs(neighbor, node, found_count);
        if (sub_count > 0)
        {                                    // 如果子树中找到重要节点
            required_nodes.insert(neighbor); // 将路径上的节点加入集合
            count += sub_count;
        }
    }

    if (count > 0)
    {
        required_nodes.insert(node); // 将当前节点加入集合
    }

    found_count += count;
    return count;
}

int main()
{
    int N, K;
    cin >> N >> K;

    for (int i = 1; i < N; ++i)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    vector<int> V(K);
    for (int i = 0; i < K; ++i)
    {
        cin >> V[i];
        important[V[i]] = true; // 标记重要节点
    }

    int found_count = 0;
    dfs(V[0], -1, found_count); // 从任意一个指定节点开始 DFS

    cout << required_nodes.size() << endl; // 输出最小子树的节点数

    return 0;
}
