package com.zhangchi.dsa;

import java.util.ArrayList;

/**
 * LeetCode
 * 236. Lowest Common Ancestor of a Binary Tree
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 *
 * According to the definition of LCA on Wikipedia:
 * “The lowest common ancestor is defined between two nodes v and w as the lowest
 * node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
 *
 *              _______3______
              /               \
           ___5__           ___1__
          /      \         /      \
          6      _2        0       8
               /  \
               7   4
 *
 * For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a
 * node can be a descendant of itself according to the LCA definition.
 *
 * @author zhangchi
 * @date 2018/1/20
 *
 */
public class LowestCommonAncestor {

    private static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    /**
     * 解法一
     * @param root
     * @param p
     * @param q
     * @return
     */
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == p || root == q) return root;
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        return left == null ? right : right == null ? left : root;
    }

    /**
     * 解法二，通过计算路径，转换为求2个List的第一个公共节点
     * （Leetcode can't ac, but lintcode can） = =！
     * @param root
     * @param p
     * @param q
     * @return
     */
    public TreeNode lowestCommonAncestor1(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null)
            return null;

        ArrayList<TreeNode> path1 = new ArrayList<TreeNode>();
        boolean find1 = findPath(root, p , path1);

        ArrayList<TreeNode> path2 = new ArrayList<TreeNode>();
        boolean find2 = findPath(root, q , path2);

        TreeNode lca = null;
        if (!find1 || !find2){
            // 如果只找到其中一个节点，则该节点就是ancestor
            if (find1)
                return path1.get(path1.size() - 1);
            if (find2)
                return path1.get(path2.size() - 1);
        }
        else {
            for (int i = 0; i < path1.size() && i < path2.size(); ++i){
                if (path1.get(i) != path2.get(i))
                    break;
                else
                    lca = path1.get(i);
            }
        }

        return lca;
    }

    private boolean findPath(TreeNode root, TreeNode target, ArrayList<TreeNode> path){
        if (root == null)
            return false;

        path.add(root);
        if (root == target)
            return true;

        if(findPath(root.left, target, path) || findPath(root.right, target, path))
            return true;
        else {
            path.remove(path.size() - 1);
            return false;
        }
    }


    public static void test(TreeNode root, TreeNode p, TreeNode q)
    {
        LowestCommonAncestor LCA = new LowestCommonAncestor();
        TreeNode lca = LCA.lowestCommonAncestor(root, p, q);
        System.out.println(lca != null ? lca.val : null);
    }

    public static void main(String[] args){
        TreeNode root = new TreeNode(3);
        TreeNode node5 = root.left = new TreeNode(5);
        TreeNode node1 = root.right = new TreeNode(1);
        root.left.left = new TreeNode(6);
        root.left.right = new TreeNode(2);
        root.left.right.left = new TreeNode(7);
        TreeNode node4 = root.left.right.right = new TreeNode(4);
        root.right.left = new TreeNode(0);
        root.right.right = new TreeNode(8);

        test(root, new TreeNode(10), new TreeNode(11));
        test(root, node1, null);
        test(root, node5, node4);
    }

}
