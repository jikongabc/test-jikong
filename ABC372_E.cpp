#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind
{
public:
    vector<int> parent, size;
    vector<vector<int>> top10; // 维护每个连通分量的前10大顶点

    UnionFind(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        top10.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            parent[i] = i;
            top10[i].push_back(i); // 每个连通分量开始时只有自己一个顶点
        }
    }

    int find(int u)
    {
        if (parent[u] != u)
        {
            parent[u] = find(parent[u]); // 路径压缩
        }
        return parent[u];
    }

    void unite(int u, int v)
    {
        int root_u = find(u);
        int root_v = find(v);

        if (root_u != root_v)
        {
            if (size[root_u] < size[root_v])
            {
                swap(root_u, root_v);
            }
            // 合并 root_v 到 root_u
            parent[root_v] = root_u;
            size[root_u] += size[root_v];

            // 合并两个前10大顶点列表
            vector<int> merged = top10[root_u];
            merged.insert(merged.end(), top10[root_v].begin(), top10[root_v].end());
            sort(merged.rbegin(), merged.rend()); // 从大到小排序

            // 只保留前10个
            if (merged.size() > 10)
            {
                merged.resize(10);
            }

            top10[root_u] = merged;
            top10[root_v].clear(); // 清空被合并的顶点列表
        }
    }

    vector<int> get_top10(int v)
    {
        return top10[find(v)]; // 获取v所在连通分量的前10大顶点
    }
};

int main()
{
    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    for (int i = 0; i < Q; ++i)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int u, v;
            cin >> u >> v;
            uf.unite(u, v);
        }
        else if (type == 2)
        {
            int v, k;
            cin >> v >> k;
            vector<int> top = uf.get_top10(v);

            if (top.size() < k)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << top[k - 1] << endl; // 输出第k大的顶点
            }
        }
    }

    return 0;
}
