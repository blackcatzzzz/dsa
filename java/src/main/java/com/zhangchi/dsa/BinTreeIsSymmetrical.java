package com.zhangchi.dsa;

/**
 * 剑指Offer 59.
 * 判断一个二叉树是否是镜像二叉树
 *
 * @author Chi Zhang
 * @date 2018/1/21
 */

public class BinTreeIsSymmetrical {

    private static class TreeNode {
        int val = 0;
        TreeNode left = null;
        TreeNode right = null;
        public TreeNode(int val) {
            this.val = val;
        }
    }

    boolean isSymmetrical(TreeNode pRoot){
        if(pRoot == null)
            return true;
        if(pRoot.left == null && pRoot.right == null)
            return true;
        if(pRoot.left == null || pRoot.right == null)
            return false;
        if(pRoot.left.val != pRoot.right.val)
            return false;

        return isSymmetrical(pRoot.left, pRoot.right); // 对原书中算法进行优化，避免节点重复判断，原书为(pRoot,pRoot)
    }

    boolean isSymmetrical(TreeNode root1, TreeNode root2){
        if(root1 == null && root2 == null)
            return true;

        if(root1 == null || root2 == null)
            return false;

        if(root1.val != root2.val)
            return false;
        return isSymmetrical(root1.left, root2.right)
                && isSymmetrical(root1.right, root2.left);
    }

    public static void main(String[] args) {
    }
}
