package com.zhangchi.dsa;


import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

/**
 * @auther zhangchi
 * @date 2018/1/15
 */
public class BinTree {

    public static ArrayList<Integer> travPre_R(BinNode root){
        ArrayList<Integer> arrayList = new ArrayList<Integer>();
        if (root == null)
            return arrayList;
        travPre_R(root, arrayList);

        return arrayList;
    }

    public static void travPre_R(BinNode root, ArrayList<Integer> arrayList) {
        arrayList.add(root.val);
        if (root.left != null)
            travPre_R(root.left, arrayList);
        if (root.right != null)
            travPre_R(root.right, arrayList);
    }

    public static ArrayList<Integer> travIn_R(BinNode root){
        ArrayList<Integer> arrayList = new ArrayList<Integer>();
        if (root == null)
            return arrayList;
        travIn_R(root, arrayList);

        return arrayList;
    }

    public static void travIn_R(BinNode root, ArrayList<Integer> arrayList) {
        if (root.left != null)
            travIn_R(root.left, arrayList);
        arrayList.add(root.val);
        if (root.right != null)
            travIn_R(root.right, arrayList);
    }

    public static ArrayList<Integer> travPost_R(BinNode root){
        ArrayList<Integer> arrayList = new ArrayList<Integer>();
        if (root == null)
            return arrayList;
        travPost_R(root, arrayList);

        return arrayList;
    }

    public static void travPost_R(BinNode root, ArrayList<Integer> arrayList) {
        if (root.left != null)
            travPost_R(root.left, arrayList);
        if (root.right != null)
            travPost_R(root.right, arrayList);
        arrayList.add(root.val);
    }

    // 前序遍历递归版本
    public static void travPre(BinNode root){
        if (root == null)
            return;
        Stack<BinNode> stack = new Stack<BinNode>();
        stack.push(root);
        while(!stack.isEmpty()){
            BinNode x = stack.pop();
            while (x != null)
            {
                System.out.print(x.val + " ");
                if (x.right != null)
                    stack.push(x.right);
                x = x.left;
            }
        }
    }

    public static void travIn(BinNode root){
        if(root == null)
            return;
        
    }

    public static void travLevel(BinNode root){
        if(root == null)
            return;

        Queue<BinNode> q = new LinkedList<BinNode>();
        q.offer(root);
        while (!q.isEmpty()){
            BinNode x = q.poll();
            System.out.print(x.val + " ");
            if(x.left != null)
                q.offer(x.left);
            if (x.right != null)
                q.offer(x.right);
        }
    }

    /**
     *
     * @param pre preoder sequence
     * @param in in sequence
     * @return BinTree
     */
    public static BinNode reConstructBinaryTree(int [] pre,int [] in) {
        if(pre.length == 0 || in.length == 0)
            return null;


        BinNode root = reConstructBinaryTreeCore(pre, 0, pre.length - 1,
                in, 0, in.length - 1);


        return root;
    }

    public static BinNode reConstructBinaryTreeCore(int [] pre, int preLo, int preHi, int [] in, int inLo, int inHi) {
        BinNode x = new BinNode(pre[preLo]);

        int i = 0;
        for (; i < in.length && x.val != in[i]; ++i)

        if(i == in.length)
            return  null; // 非法序列

        int leftLen = i - inLo;
        int rightLen = inHi - i;
        if(leftLen > 0)
            x.left = reConstructBinaryTreeCore(pre, preLo + 1, preLo + leftLen,
                    in, inLo, i - 1);
        if (rightLen > 0)
            x.right = reConstructBinaryTreeCore(pre, preLo + leftLen + 1, preHi,
                    in, i + 1, inHi);

        return  x;
    }

    public static <T> void printArray(T[] arr){
        for(T e : arr)
            System.out.print(e + " ");
        System.out.println();
    }

    public static void main(String[] args){
        BinNode root = new BinNode(1);
        BinNode n2 = root.left = new BinNode(2);
        BinNode n3 = root.right = new BinNode(3);
        n2.left = new BinNode(4);
        n2.right = new BinNode(5);
        n3.left = new BinNode(6);
        n3.right = new BinNode(7);

        System.out.print("travLevel: \t");
        travLevel(root);
        System.out.println();

        System.out.print("travPre: \t");
        travPre(root);
        System.out.println();

        System.out.print("travPre_R: \t");
        printArray(travPre_R(root).toArray());

        System.out.print("travIn_R: \t");
        printArray(travIn_R(root).toArray());

        System.out.print("travPost_R: ");
        printArray(travPost_R(root).toArray());

        BinNode reConBinTree = reConstructBinaryTree(travPre_R(root).stream().mapToInt(i->i).toArray(), travIn_R(root).stream().mapToInt(i->i).toArray());
        System.out.print("travLevel(reConstrucet): ");
        travLevel(reConBinTree);
    }
}

class BinNode{
    int val;
    BinNode left;
    BinNode right;

    BinNode(int val){
        this.val = val;
    }
}

//interface BinTreeCallback{
//    void getTravSequence(Integer val);
//}
//
//class BinTreeVisit implements BinTreeCallback{
//    private ArrayList<Integer> travSequence = new ArrayList<Integer>();
//
//    @Override
//    public void getTravSequence(Integer val) {
//        travSequence.add(val);
//        return null;
//    }
//}