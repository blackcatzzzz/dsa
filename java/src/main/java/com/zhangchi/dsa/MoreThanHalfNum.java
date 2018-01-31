package com.zhangchi.dsa;

/**
 * 超过一半的数字
 * @author Chi Zhang
 * @date 2018/1/31
 */
public class MoreThanHalfNum {

    /**
     *
     * @param array
     * @return
     */
    public int moreThanHalfNum(int[] array) {
        if(array == null || array.length == 0)
            return 0; // 假定不存在，返回0

        int candidate = candidateByPartition(array);

        if(candidateCheck(array, candidate))
            return candidate;
        else
            return 0;
    }

    /**
     * 选出候选者（满足必要条件）
     * 方法一：使用剪除法，计数器线性扫描
     * @return
     */
    private int candidateByCount(int[] array){
        int count = 0;
        int candidate = 0;
        for (int i = 0; i < array.length; ++i){
            if (count == 0){            //每当count归零，都意味着此时的前缀P可以剪除
                candidate = array[i];
                count = 1;
            }else{
                if (candidate == array[i])
                    ++count;
                else
                    --count;
            }
        }

        return candidate;
    }

    /**
     * 选出候选者（满足必要条件：若存在必为中位数）
     * @param array
     * @return
     */
    private int candidateByPartition(int[] array){
        int lo = 0, hi = array.length -1;
        int mid = (lo + hi) >> 1;
        int index = partition(array, lo, hi);

        while(index != mid){
            if (index < mid)
                index = partition(array, index + 1, hi);
            else
                index = partition(array, lo, index - 1);
        }

        return array[index];
    }

    /**
     * 快速对数组分区，返回index;在index左边的均不大于array[index],在index右边的均不小于array[index]
     * [lo,hi]
     * @param array
     * @param lo
     * @param hi
     * @return
     */
    private int partition(int[] array, int lo, int hi){
//        if(lo >= hi)
//            return lo;
        int pivot = array[lo];

        while (lo < hi){
            while(lo < hi && pivot <= array[hi])
                --hi;
            array[lo] = array[hi];

            while(lo < hi && array[lo] <= pivot)
                ++lo;
            array[hi] = array[lo];
        }

        array[lo] = pivot;

        return lo;
    }

    /**
     * 检查候选者是否为超过一半的的数
     * @param array
     * @param candidate
     * @return
     */
    private boolean candidateCheck(int[] array, int candidate){
        int count = 0;
        for (int i = 0; i < array.length; ++i){
            if (array[i] == candidate)
                ++count;
        }

        return count > array.length / 2;
    }

    public static void main(String[] args) {
        int[] array = {2,3,2,2,2,6,1};
        MoreThanHalfNum mthn = new MoreThanHalfNum();
        System.out.println(mthn.moreThanHalfNum(array));
    }
}
