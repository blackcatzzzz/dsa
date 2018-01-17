package com.zhangchi.dsa;

import java.util.ArrayList;
import java.util.List;

/**
 * LeetCode
 * 257. Binary Tree Paths
 * http://blog.csdn.net/crazy1235/article/details/51474128
 */
public class BinTreePaths {

        public List<String> binaryTreePaths(TreeNode root) {
            List<String> allPaths = new ArrayList<String>();
            if(root == null)
                return allPaths;
            binaryTreePathsCore(root, allPaths, new StringBuilder());
            return allPaths;
        }

        private void binaryTreePathsCore(TreeNode x, List<String> allPaths, StringBuilder sb){
            if (x == null)
                return;

            int len = sb.length();
            sb.append(x.val);

            if (x.left == null && x.right == null)
                allPaths.add(sb.toString());
            else{
                sb.append("->");
                if (x.left != null)
                    binaryTreePathsCore(x.left, allPaths, sb);
                if (x.right != null)
                    binaryTreePathsCore(x.right, allPaths, sb);
            }

            sb.setLength(len);
        }

        public static void main(String[] args) {
            TreeNode root = new TreeNode(1);
            root.left = new TreeNode(2);
            root.right = new TreeNode(3);
            root.left.right = new TreeNode(5);

            BinTreePaths bintreePath = new BinTreePaths();
            List<String> allPaths = bintreePath.binaryTreePaths(root);
        }
}
