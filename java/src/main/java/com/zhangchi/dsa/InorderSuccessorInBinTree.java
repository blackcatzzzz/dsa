package com.zhangchi.dsa;

/**
 * 剑指Offer 58.
 * 找出二叉树中序遍历的下一个节点
 *
 * @author Chi Zhang
 * @date 2018/1/21
 */
public class InorderSuccessorInBinTree {

    private static class TreeLinkNode {
        int val;
        TreeLinkNode left = null;
        TreeLinkNode right = null;
        TreeLinkNode next = null;

        TreeLinkNode(int val) {
            this.val = val;
        }

        TreeLinkNode(int val, TreeLinkNode left, TreeLinkNode right, TreeLinkNode next) {
            this.val = val;
            this.left = left;
            this.right = right;
            this.next = next;
        }
    }

    public TreeLinkNode getNext(TreeLinkNode pNode){
        if(pNode == null)
            return pNode;

        TreeLinkNode x = null; //记录后继的临时变量
        if(pNode.right != null){ //若有右孩子，则直接后继必在右子树中，具体地就是
            x = pNode.right; //右子树中
            while(x.left != null) //最靠左（最小）的节点
                x = x.left;
        }
        else{ //否则，直接后继应是“将当前节点包含于其左子树中的最低祖先”，具体地就是
            x = pNode;
            while(x.next != null && x == x.next.right)
                x = x.next;
            x = x.next;
        }
        return x;
    }


    public static void main(String[] args){
        TreeLinkNode root = new TreeLinkNode(1);
        TreeLinkNode node2 = root.left = new TreeLinkNode(2, null,null, root);
        TreeLinkNode node3 = root.right = new TreeLinkNode(3, null,null, root);
        node2.left = new TreeLinkNode(4, null,null, node2);
        node2.right = new TreeLinkNode(5, null,null, node2);
        node3.left = new TreeLinkNode(6, null,null, node3);
        node3.right = new TreeLinkNode(7, null,null, node3);

        InorderSuccessorInBinTree isibt = new InorderSuccessorInBinTree();
        TreeLinkNode succ = isibt.getNext(node3.right);
        System.out.println((succ != null) ? succ.val : null);
    }
}
