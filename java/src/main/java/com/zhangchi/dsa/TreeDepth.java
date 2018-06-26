package com.zhangchi.dsa;

/**
 * 二叉树的深度（剑指Offer）
 * @author Chi Zhang
 * @date 2018/6/26
 */
public class TreeDepth {
    private static class TreeNode {
        int val = 0;
        TreeNode left = null;
        TreeNode right = null;

        public TreeNode(int val) {
            this.val = val;

        }
    }

    public int treeDepth(TreeNode root){
        if(root == null)
            return 0;

        return Math.max(treeDepth(root.left), treeDepth(root.right)) + 1;
    }
}

