package com.zhangchi.dsa;

/**
 * 判断一颗二叉树是否平衡(剑指Offer)
 * @author Chi Zhang
 * @date 2018/6/26
 */
public class IsBinTreeBalanced {
    private boolean isBalance = true;

    public boolean isBinTreeBalanced(TreeNode root) {
        if(root == null)
            return isBalance;
        treeDepth(root);
        return isBalance;
    }

    private int treeDepth(TreeNode root){
        if(root == null)
            return 0;

        int left = treeDepth(root.left);
        int right = treeDepth(root.right);

        if(Math.abs(left - right) > 1)
            isBalance = false;

        return Math.max(left,right) + 1;
    }

    private static class TreeNode {
        int val = 0;
        TreeNode left = null;
        TreeNode right = null;

        public TreeNode(int val) {
            this.val = val;
        }
    }
}
