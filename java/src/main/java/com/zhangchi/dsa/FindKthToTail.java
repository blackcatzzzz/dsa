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

    public static ListNode findKthToTail(ListNode head,int k) {
        if (head == null || k == 0)
            return null;

        ListNode fast = head;
        while (k-- > 0){
            if (fast == null) // 非法判断
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
