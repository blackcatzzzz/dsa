
#include "common.h"

    class UF {
    public:
        UF(int n): _count(n), parent(n, 0), size(n, 1){
            for(int i = 0; i < n; i++)
                parent[i] = i;
        }

        void unionSet(int p, int q){
            int rootP = find(p);
            int rootQ = find(q);
            if(rootP == rootQ)
                return;
            if(size[rootP] > size[rootQ]){
                parent[rootQ] = rootP;
                size[rootP] += size[rootQ];
            }else{
                parent[rootP] = rootQ;
                size[rootQ] += size[rootP];
            }

            _count--;
        }

        bool connected(int p, int q){
            int rootP = find(p);
            int rootQ = find(q);
            return rootP == rootQ;
        }

        int find(int x){
            while(parent[x] != x){
                parent[x] = parent[parent[x]];
                x = parent[x];
            }

            return x;
        }

        int count(){
            return this->_count;
        }

    private:
        int _count; // 连通分量
        vector<int> parent; // 根节点
        vector<int> size;   // 大小
    };
public:
    UF(int n): _count(n), parent(n, 0), size(n, 1){
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    void unionSet(int p, int q){
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP == rootQ)
            return;
        if(size[p] > size[q]){
            parent[q] = rootP;
            size[p] += size[q];
        }else{
            parent[p] = rootQ;
            size[q] += size[p];
        }

        _count--;
    }

    bool connected(int p, int q){
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }

    int find(int x){
        while(parent[x] != x){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }

        return x;
    }

    int count(){
        return this->_count;
    }

private:
    int _count; // 连通分量
    vector<int> parent; // 根节点
    vector<int> size;   // 大小
};