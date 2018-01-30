package com.zhangchi.dsa;

/**
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
 * @author Chi Zhang
 * @date 2018/1/30
 */
public class VerifySequenceOfBST {

    public boolean verifySequenceOfBST(int [] sequence) {
        if(sequence == null || sequence.length == 0)
            return false;
        return verifySequenceOfBSTCore(sequence, 0, sequence.length - 1);
    }

    // [lo,hi]
    private boolean verifySequenceOfBSTCore(int[] seq, int lo, int hi){
//        if(lo == hi)
//            return true;

        int root = seq[hi];
        int i = lo;
        for (; i < hi; ++i){
            if(seq[i] > root)
                break;
        }

        for (int j = i + 1; j < hi; ++j){
            if (seq[j] < root)
                return false;
        }

        boolean left = true, right = true;
        if(i > lo)
            left = verifySequenceOfBSTCore(seq, lo, i - 1);
        if(i < hi - 1)
            right = verifySequenceOfBSTCore(seq, i, hi - 1);

        return left && right;
    }
}
