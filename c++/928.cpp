class Unionfind{
public: 
    vector<int> f;
    Unionfind(int size){
        f.resize(size);
        for(int i = 0; i < size; ++i)
            f[i] = i;
    }
    int find(int x){
        if(f[x] == x)
            return x;
        else
            return find(f[x]);
    }
    void merge(int p, int q) {
        int a = find(p); int b = find(q);
        if(a != b) f[a] = b;
    }
    int getsize(int k){
        int count = 0;
        int g = find(k);
        for(int i = 0; i < f.size(); i++)
            if(find(i) == g)
                count ++;
        return count;
    }
};

class Solution {
public:
    // 过于僵硬，只一味大而统之，应思考局部破解之法
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        if(initial.size() == 1)
            return initial[0];

        int m = graph.size();
        vector<int> dead = vector<int>(m, 0);
        for(int node : initial)
            dead[node] = 1;
        
        vector<int> cur = vector<int>(m, 301);
        for(int node : initial) {
            dead[node] = 0;
            Unionfind uf(m);
            for(int i = 0; i < m-1; ++i){
                for(int j = i+1; j < m; ++j){
                    if(i == node || j == node)
                        continue;
                    if(graph[i][j] == 1)
                        uf.merge(i, j);
                    else if(dead[i] == 1 && dead[j] == 1)
                        uf.merge(i, j);
                }
            }
            if(dead[initial[0]] == 0)
                cur[node] = uf.getsize(initial[1]);
            else
                cur[node] = uf.getsize(initial[0]);
            dead[node] = 1;
        }
        return min_element(cur.begin(), cur.end()) - cur.begin();
    }
};