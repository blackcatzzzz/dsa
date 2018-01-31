package com.zhangchi.dsa;

/**
 * 有环链表的环入口
 * @author Chi Zhang
 * @date 2018/1/31
 */
public class EntryNodeOfLoop {

    private static class ListNode {
        int val;
        ListNode next = null;

        ListNode(int val) {
            this.val = val;
        }
    }

    /**
     * 方法一：
     * 1）先算出环的长度r
     * 2）ahead = head,先行指针ahead走r步;
     * 3) behind = head,后行指针和先行指针一起走，相遇的那个点就是环入口节点。
     * @param head
     * @return
     */
    public ListNode entryNodeOfLoop1(ListNode head) {
        if(head == null)
            return null;
        ListNode meetingNode = getMeetingNode(head);

        if(meetingNode == null) // 无环
            return null;

        int lenOfLoop = lengthOfLoop(meetingNode);

        ListNode ahead = head;
        while (lenOfLoop-- > 0)
            ahead = ahead.next;

        ListNode behind = head;
        while (ahead != behind){
            ahead = ahead.next;
            behind = behind.next;
        }

        return ahead;
    }

    /**
     * 环入口节点
     * 方法二：
     * 1）先找到环内碰撞节点meetingNode
     * 2）后行指针behind = head, 先行指针ahead = meetingNode, 一起走，相遇的节点即为入口节点
     *
     * 原理：
     * 1）使用快慢指针找到环内碰撞点时，slow走过距离为s,fast为2s,设r为环内长度，s + nr = 2s (n>=1)，则s = nr ①
     * 2）设x为链表头到环入口的距离，y为环入口到环内碰撞点的距离，则 s = x + y ②
     * 3）由①②得，x = nr - y ③
     * 4）设z = r - y ④
     * 5) 由③④得，x = (n - 1)r + z，也就是说当一个指针从头走过x步时，另外一个指针从meetingNode开始走K圈，再走z步后，2个指针相遇在环入口
     * @param head
     * @return
     */
    public ListNode entryNodeOfLoop2(ListNode head){
        if(head == null)
            return null;

        ListNode meetingNode = getMeetingNode(head);
        if (meetingNode == null)
            return null;

        ListNode ahead = meetingNode;
        ListNode behind = head;
        while (ahead != behind){
            ahead = ahead.next;
            behind = behind.next;
        }

        return ahead;
    }

    /**
     * 通过快慢指针找到环内碰撞的点，如果返回为null则说明无环
     * @param head
     * @return
     */
    private ListNode getMeetingNode(ListNode head){
        ListNode fast = head;
        ListNode slow = head;

        while(fast != null && fast.next != null){
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow)
                return fast;
        }

        return null;
    }

    /**
     * 获取环长度
     * 方法一：通过快慢指针计算
     * @param meetingNode
     * @return
     */
    private int lengthOfLoopByFS(ListNode meetingNode){
        if(meetingNode == null)
            return 0;

        ListNode fast = meetingNode;
        ListNode slow = meetingNode;

        int count = 0;
        do{
            ++count;
            fast = fast.next.next;
            slow = slow.next;
        }while(fast != slow);

        return count;
    }

    /**
     * 获取环长度
     * 方法二：从碰撞点出发，走一圈直到回到碰撞点
     * @param meetingNode
     * @return
     */
    private int lengthOfLoop(ListNode meetingNode){
        ListNode x = meetingNode;
        int count = 0;
        do{
            ++count;
            x = x.next;
        }while(x != meetingNode);
        return count;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        ListNode node2 = head.next = new ListNode(2);
        ListNode node3 = node2.next = new ListNode(3);
        ListNode node4 = node3.next = new ListNode(4);
        ListNode node5 = node4.next = new ListNode(5);
        ListNode node6 = node5.next = new ListNode(6);
        ListNode node7 = node6.next = new ListNode(7);
        node7.next = node3; // node3 为环入口

        EntryNodeOfLoop enol = new EntryNodeOfLoop();
        ListNode entryNodeOfLoop = enol.entryNodeOfLoop2(head);
        System.out.println(entryNodeOfLoop == null ? null : entryNodeOfLoop.val);
    }
}
