package com.zhangchi.dsa;

import java.util.Stack;

/**
 * 包含min函数的栈
 * @author Chi Zhang
 * @date 2018/1/30
 */
public class StackForMin {
    private Stack<Integer> stackMin = new Stack<>();
    private Stack<Integer> stack = new Stack<>();

    public void push(int node) {
        stack.push(node);
        if (stackMin.isEmpty())
            stackMin.push(node);
        else {
            if (node < stackMin.peek())
                stackMin.push(node);
            else
                stackMin.push(stackMin.peek());
        }
    }

    public void pop() {
        stackMin.pop();
        stack.pop();
    }

    public int top() {
        return stack.peek();
    }

    public int min() {
        return stackMin.peek();
    }
}
