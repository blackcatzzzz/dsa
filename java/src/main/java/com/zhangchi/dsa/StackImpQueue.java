package com.zhangchi.dsa;

import java.util.Stack;

/**
 * 用栈实现队列
 */
public class StackImpQueue {

    private Stack<Integer> stack1 = new Stack<>();
    private Stack<Integer> stack2 = new Stack<>();

    public void push(int node) {
        stack1.push(node);
    }

    public int pop() {
        if (stack2.isEmpty()){
            while (!stack1.isEmpty())
                stack2.push(stack1.pop());
        }
        assert (!stack2.isEmpty());
        return stack2.pop();
    }
}
