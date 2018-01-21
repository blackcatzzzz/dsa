package com.zhangchi.dsa;

import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;

/**
 * LeetCode 297. Serialize and Deserialize Binary Tree
 * LintCode 7. Binary Tree Serialization
 * 剑指Offer 62.
 *
 * @author Chi Zhang
 * @date 2018/1/21
 */
public class BinTreeSerialize {

    private static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    private static final String NN = "#"; // use "#" to denote null node
    private static final String delimiter = ",";

    /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     *
     * 前序遍历解法
     */
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        buildString(root, sb);
        return sb.toString();
    }

    private void buildString(TreeNode node, StringBuilder sb){
        if (node == null)
            sb.append(NN).append(delimiter);
        else{
            sb.append(node.val).append(delimiter);
            buildString(node.left, sb);
            buildString(node.right, sb);
        }
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     *
     * 前序遍历解法
     */
    public TreeNode deserialize(String data) {
        Queue<String> values = new LinkedList<>();
        values.addAll(Arrays.asList(data.split(delimiter)));
        return buildTree(values);
    }

    //
    private TreeNode buildTree(Queue<String> values){
        String value = values.poll();
        if (value.equals(NN))
            return null;
        TreeNode node = new TreeNode(Integer.valueOf(value));
        node.left = buildTree(values);
        node.right = buildTree(values);

        return node;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        TreeNode node2 = root.left = new TreeNode(2);
        TreeNode node3 = root.right = new TreeNode(3);
        node2.left = new TreeNode(4);
        node2.right = new TreeNode(5);
        node3.left = new TreeNode(6);
        node3.right = new TreeNode(7);

        BinTreeSerialize bts = new BinTreeSerialize();
        System.out.println(bts.deserialize(bts.serialize(root)).val);
    }
}
