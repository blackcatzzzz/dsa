package com.zhangchi.dsa;

/**
 * 调整数组，使得奇数在前，偶数在后，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 * @author Chi Zhang
 * @date 2018/1/30
 */
public class ReOrderArray {

    /**
     * 方法一
     * 时间复杂度O（n）,需要辅助空间
     * @param array
     */
    public void reOrderArray(int[] array) {
        if(array == null || array.length == 1)
            return;

        int len = array.length;
        int[] oddArray = new int[len];
        int[] evenArray = new int[len];

        int oddCount = 0;
        int evenCount = 0;
        for (int i = 0; i < len; ++i){
            if (array[i] % 2 == 0)
                evenArray[evenCount++] = array[i];
            else
                oddArray[oddCount++] = array[i];
        }

        for (int i = 0; i < oddCount; ++i)
            array[i] = oddArray[i];
        for (int i = 0; i < evenCount; ++i)
            array[oddCount + i] = evenArray[i];
    }

    /**
     * 方法二,常数辅助空间
     * 1)假设数组分为2个连续子序列部分，前一部分A为奇数，后一部分B为偶数,insertIndex表示奇数序列下一个要插入的位置，即尾部，显然insertIndex开始为0；
     * 2)遍历数组
     * 2.1)如果a[i]为奇数，且i == insertIndex,则insertIndex++，自然扩展奇数序列；
     * 2.2)如果a[i]为奇数，且i != insertIndex,则需插入A的尾部；不过需要先将（i - 1） ~ insertIndex元素均向后移动一位，然后插入a[i]到insertIndex
     */
    public void reOrderArray1(int[] array){
        if(array == null || array.length == 1)
            return;

        int insertIndex = 0;
        int i = 0;
        for (; i < array.length; ++i){
            if (array[i] % 2 != 0){
                if(i != insertIndex){
                    int temp = array[i];
                    for (int j = i; j > insertIndex; --j)
                        array[j] = array[j - 1];
                    array[insertIndex++] = temp;
                }else {
                    insertIndex++;
                }
            }
        }
    }

    public static void print(int[] array){
        for (int i = 0; i < array.length; ++i)
            System.out.print(array[i] + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        int[] array = {5,1,3,2,6,11,4,7};
        print(array);
        ReOrderArray r = new ReOrderArray();
        r.reOrderArray1(array);
        print(array);
    }
}
