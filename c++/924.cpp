class DSU {
public:
    vector<int> F;
    vector<int> nodeSize; // 每个节点连通块大小

    DSU (int N) {
        F.resize(N, 0);
        for (int i = 0; i < N; i++) {
            F[i] = i;
        }
        nodeSize.resize(N, 1);
    }

    int Find(int x) {
        if (x != F[x]) F[x] = Find(F[x]);
        return F[x];
    }

    void Union(int x, int y) {
        int fx = Find(x);
        int fy = Find(y);

        F[fx] = fy;
        // Be Careful
        if (fx != fy) {
            nodeSize[fy] += nodeSize[fx];
        }
    }

    int GetSize(int x) {
        return nodeSize[Find(x)];
    }
};

class Solution {
public:
    /*
    思路：
    一、并查集-涂色思路
    1、划分当前graph里的连通分量块，同时计算了每个连通分量块的大小，并查集union计算
    2、计算initial表中的每个分量块的大小，对于大于1的块，每次删除一个节点是没法缩减整个感染节点数的，所以只需要针对连通分量块为1的进行处理
    3、连通分量块为1的时候，搜索该块在原表中的实际大小，找到最大的块进行删除即可得到最少的感染节点，块大小相等时返回索引最小的点
    4、不存在连通分量块为1的情况，返回initial中最小值
    */
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        DSU dsu(graph.size());

        sort(initial.begin(), initial.end());
        // 计算graph中连通分量块
        for (int i = 0; i < graph.size(); i++) {
            for (int j = i + 1; j < graph[0].size(); j++) {
                if (graph[i][j] == 1) {
                    dsu.Union(i, j);
                }
            }
        }
        // 计算initial中共连通块元素个数
        map<int, int> inicount;
        for (auto c : initial) {
            inicount[dsu.Find(c)]++;
        }

        int ans = -1;
        int maxsize = -1;
        for (auto c : initial) {
            if (inicount[dsu.Find(c)] == 1) {
                int nodesize = dsu.GetSize(c);
                if (nodesize > maxsize) {
                    maxsize = nodesize;
                    ans = c;
                }
            }
        }
        if (ans == -1) return initial[0];
        return ans;
    }
};