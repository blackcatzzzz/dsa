package com.zhangchi.dsa;

/**
 * 链表中的倒数第K个节点
 * @author Chi Zhang
 * @date 2018/1/30
 */
public class FindKthToTail {

    private static class ListNode{
        int val;
        ListNode next;

        ListNode(int val){
            this.val = val;
        }
    }

    /**
     * 思路：
     * 1）假设有n的节点，那么要找到倒数第K个节点，需从头结点开始连续走n-k步。例如：1->2->3->4->5, n=5,k=2.连续走n-k=3步。
     * 2）fast先走k步，此时fast走到尾部哨兵节点剩下n-k步
     * 3）slow指向head,slow和fast同时走，当fast走到尾部哨兵节点时，slow走了n-k步，即指向了倒数k个节点
     * @param head
     * @param k
     * @return
     */
    public static ListNode findKthToTail(ListNode head,int k) {
        if (head == null || k == 0)
            return null;

        ListNode fast = head;
        while (k-- > 0){
            if (fast == null) // 非法判断，k大于链表长度
                return null;
            fast = fast.next;
        }

        ListNode slow = head;
        while (fast != null){
            fast = fast.next;
            slow = slow.next;
        }

        return slow;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        ListNode node2 = head.next = new ListNode(2);
        ListNode node3 = node2.next = new ListNode(3);
        ListNode node4 = node3.next = new ListNode(4);
        ListNode node5 = node4.next = new ListNode(5);
        ListNode result = FindKthToTail.findKthToTail(head, 1);
        System.out.println(result == null ? null : result.val);
    }
}
