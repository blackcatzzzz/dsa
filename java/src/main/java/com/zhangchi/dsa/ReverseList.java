package com.zhangchi.dsa;

import java.util.ArrayList;
import java.util.Stack;

/**
 * Reverse list
 * @author zhangchi
 * @date 2018/1/15
 */
public class ReverseList {
    public static ListNode AddNode(ListNode head, int val){
        ListNode node = new ListNode(val);
        if (head == null)
            head = node;
        else
        {
            ListNode p = head;
            while (p.next != null)
                p = p.next;

            p.next = node;
        }
        return head;
    }

    // Reverse list
    public static ListNode Reverse(ListNode head){
        if(head == null)
            return head;

        ListNode prev = null;
        ListNode cur = head;
        ListNode temp;

        while(cur != null){
            temp = cur.next;
            cur.next = prev;
            prev = cur;
            cur = temp;
        }

        return prev;
    }

    public static void printList(ListNode head){
        while (head != null)
        {
            System.out.print(head.val + " ");
            head = head.next;
        }
        System.out.println();
    }

    public static <T> void printArray(T[] arr){
        for(T e : arr)
            System.out.print(e + " ");
        System.out.println();
    }


    // 从尾到头打印链表（nowcoder,3）
    public static ArrayList<Integer> printListFromTailToHead(ListNode head){
        if (head == null)
            return  null;
        ArrayList<Integer> arrayList = new ArrayList<Integer>();
        Stack<Integer> stack = new Stack<Integer>();

        ListNode p = head;
        while(p != null)
        {
            stack.push(p.val);
            p = p.next;
        }

        while (!stack.empty())
            arrayList.add(stack.pop());

        return arrayList;
    }

    public static void main(String[] args){
        ListNode head = new ListNode(1);
        ReverseList.AddNode(head, 2);
        ReverseList.AddNode(head, 3);
        ReverseList.AddNode(head, 4);
        printArray(printListFromTailToHead(head).toArray());
        printList(head);
        ListNode newHead = ReverseList.Reverse(head);
        printList(newHead);

        return;
    }
}

class ListNode{
    int val;
    ListNode next;

    ListNode(int val){
        this.val = val;
    }
}
