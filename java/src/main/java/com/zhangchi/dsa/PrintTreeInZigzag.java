package com.zhangchi.dsa;

import sun.reflect.generics.tree.Tree;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Stack;

public class PrintTreeInZigzag {

    private static class TreeNode {
        int val = 0;
        TreeNode left = null;
        TreeNode right = null;
        public TreeNode(int val) {
            this.val = val;
        }
    }

    public ArrayList<ArrayList<Integer> > print(TreeNode pRoot) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        if(pRoot == null)
            return result;

        // 第0个Stack保存奇数层节点，第1个Stack保存偶数层节点。 （假定根节点为1层）
        Stack<TreeNode>[] stack = new Stack[]{new Stack<TreeNode>(), new Stack<TreeNode>()};
        int current = 0; // 当前需要打印节点的栈数组下标
        int next = 1;
        stack[current].push(pRoot);

        ArrayList<Integer> levelNodes = new ArrayList<Integer>();
        while(!stack[current].isEmpty() || !stack[next].isEmpty()){
            TreeNode x = stack[current].pop();
            levelNodes.add(x.val);
            if(current == 0){ // 当前层为奇数层，则下一层为偶数层（从右往左打印，对应从左往右进栈）
                if(x.left != null)
                    stack[next].push(x.left);

                if(x.right != null)
                    stack[next].push(x.right);
            }
            else{
                if(x.right != null)
                    stack[next].push(x.right);

                if(x.left != null)
                    stack[next].push(x.left);
            }

            if(stack[current].isEmpty()){
                result.add(levelNodes);
                levelNodes = new ArrayList<Integer>();
                current = 1 - current;
                next = 1 - next;
            }
        }

        return result;
    }

    public static void print(ArrayList<ArrayList<Integer>> arrayLists){
        for (ArrayList<Integer> arrayList : arrayLists){
            for (Integer i : arrayList){
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args){
        TreeNode root = new TreeNode(1);
        TreeNode node2 = root.left = new TreeNode(2);
        TreeNode node3 = root.right = new TreeNode(3);
        node2.left = new TreeNode(4);
        node2.right = new TreeNode(5);
        node3.left = new TreeNode(6);
        node3.right = new TreeNode(7);

        PrintTreeInZigzag ptzz = new PrintTreeInZigzag();
        print(ptzz.print(root));
    }
}
