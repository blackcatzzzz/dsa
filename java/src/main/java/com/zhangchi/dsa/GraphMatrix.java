package com.zhangchi.dsa;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class GraphMatrix{

    private Object[] V; // 顶点集（数组）
    private int[][] E; // 边集（邻接矩阵）
    private boolean[] visited;

    // 顶点：
    private int maxNumV; // 最大顶点数
    private int numV; // 顶点总数

    // 边：
    private int numE; // 边总数

    public GraphMatrix(){
        numV = numE = 0;
    }

    public GraphMatrix(int maxNumV){
        this.maxNumV = maxNumV;
        numV = numE = 0;
        V = new Object[maxNumV];
        visited = new boolean[maxNumV];
        E = new int[maxNumV][maxNumV];
    }

    // 插入顶点，返回编号
    public int insert(Object vertex){
        assert(vertex != null);
        assert (numV < maxNumV);
        V[numV] = vertex;
        return ++numV;
    }


    // 插入边e = (i, j)
    public void insert(int i, int j){
        assert (i >=0 && j >=0);
        E[i][j] = 1;
        ++numE;
        return;
    }

    // 所有顶点、边的辅助信息复位
    private void reset(){
        for (int i = 0; i < numV; ++i)
            visited[i] = false;
    }

    /**
     * 深度优先搜索（全图），递归版
     */
    public void dfs_r(){
        reset();
        for (int i = 0; i < numV; ++i){
            if (!visited[i])
                DFS(i);
        }
    }

    /**
     * 深度优先搜索（全图），迭代版
     */
    public void dfs_i(){
        reset();
        for (int i = 0; i < numV; ++i){
            if (!visited[i])
                DFS_I(i);
        }
    }

    /**
     * 深度优先搜索(单个连通域)，递归版
     * @param v 从编号为v的顶点遍历
     */
    public void DFS(int v){
        System.out.print(V[v] + " ");
        visited[v] = true;
        for(int u = firstAdjV(v); u != -1; u = nextAdjV(v, u)) {
            if (!visited[u])
                DFS(u);
        }
    }

    /**
     * 深度优先搜索(单个连通域)，迭代版
     * @param v 从编号为v的顶点遍历
     */
    public void DFS_I(int v){
        Stack<Integer> stack = new Stack<Integer>();
        stack.push(v);
        visited[v] = true;
        while(!stack.isEmpty()){
            v = stack.pop();
            System.out.print(V[v] + " ");
            for (int u = firstAdjV(v); u != -1; u = nextAdjV(v, u)) {
                if (!visited[u]){
                    stack.push(u);
                    visited[u] = true;
                }
            }
        }
    }

    /**
     * 广度优先搜索（全图）
     */
    public void bfs(){
        reset();
        for (int i = 0; i < numV; ++i){
            if (!visited[i])
                BFS(i);
        }
    }

    /**
     * 广度优先搜索（单个连通域）
     * @param v
     */
    public void BFS(int v){
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.offer(v);
        visited[v] = true;
        while (!queue.isEmpty()){
            v = queue.poll();
            System.out.print(v + " ");
            for (int u = firstAdjV(v); u != -1; u = nextAdjV(v, u)){
                if (!visited[u]){
                    queue.offer(u);
                    visited[u] = true;
                }
            }
        }
    }


    // 顶点v的首个邻接顶点
    private int firstAdjV(int i){
        return nextAdjV(i , -1);
    }

    // 顶点i的（相对于顶点j的）下一邻接顶点
    private int nextAdjV(int i, int j){
        for (j = j + 1; j < numV; ++j)
        {
            if (E[i][j] == 1)
                return j;
        }

        return -1;
    }

    public void printG(){
        System.out.println("顶点集：");
        for(int i = 0; i < numV; ++i){
            System.out.print(V[i] + " ");
        }
        System.out.println();

        System.out.println("邻接矩阵：");
        for(int i = 0; i < numV; ++i){
            for(int j = 0; j < numV; ++j){
                System.out.print(E[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }


    public static void main(String[] args){
        GraphMatrix gm = new GraphMatrix(10);
        gm.insert(0);
        gm.insert(1);
        gm.insert(2);
        gm.insert(3);
        gm.insert(4);
        gm.insert(5);

        gm.insert(6);

        gm.insert(0, 1);
        gm.insert(0, 2);
        gm.insert(1, 3);
        gm.insert(1, 4);
        gm.insert(2, 1);
        gm.insert(2, 4);
        gm.insert(3, 5);
        gm.insert(2, 4);
        gm.insert(4, 5);

        gm.insert(6, 5); // 第二个连通域


        gm.printG();
        System.out.print("dfs_r: ");
        gm.dfs_r();
        System.out.println();

        System.out.print("dfs_i: ");
        gm.dfs_i();
        System.out.println();

        System.out.print("bfs: ");
        gm.bfs();
        System.out.println();
    }
}

//class Vertex<Tv>{
//
//}