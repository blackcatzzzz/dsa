package com.zhangchi.dsa;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

/**
 * 剑指Offer 60. 把二叉树打印成多行
 *
 * @author Chi Zhang
 * @date 2018/1/21
 */

public class PrintTreeInLines {

    private static class TreeNode {
        int val = 0;
        TreeNode left = null;
        TreeNode right = null;
        public TreeNode(int val) {
            this.val = val;
        }
    }

    ArrayList<ArrayList<Integer> > Print(TreeNode pRoot) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        if(pRoot == null)
            return result;

        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.offer(pRoot);
        int toBePrinted = 1; // 当前要打印的节点数
        int nextLevelNums = 0; // 下一层的节点数

        ArrayList<Integer> levelNodes = new ArrayList<Integer>();
        while(!q.isEmpty()){
            TreeNode x = q.poll();
            levelNodes.add(x.val);
            --toBePrinted;
            if(x.left != null){
                q.offer(x.left);
                ++nextLevelNums;
            }

            if(x.right != null){
                q.offer(x.right);
                ++nextLevelNums;
            }

            if(toBePrinted == 0){
                result.add(levelNodes);
                toBePrinted = nextLevelNums;
                nextLevelNums = 0;
                levelNodes = new ArrayList<Integer>();
            }
        }

        return result;
    }
}
