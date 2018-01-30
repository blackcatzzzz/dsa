package com.zhangchi.dsa;

/**
 * 数字中二进制1的个数
 * @author Chi Zhang
 * @date 2018/1/30
 */
public class NumberOf1 {

    /**
     * 方法一，JAVA中的 >>> 是补0，不会像C++一样产生死循环
     * @param n
     * @return
     */
    public static int numberOf1(int n){
        int count = 0;
        while (n != 0){
            if ((n & 1) != 0)
                count++;
            n = n >>> 1;
        }
        return count;
    }

    /**
     * 方法二，将1不断左移，然后与n按位与
     * @param n
     * @return
     */
    public static int numberOf1_mask(int n){
        int count = 0;
        int mask = 1;
        while(mask != 0){
            if((n & mask) != 0)
                ++count;
            mask = mask << 1;
        }

        return count;
    }

    /**
     * 方法三，最优方法 使用n&(n-1)
     * @param n
     * @return
     */
    public static int numberOf1_best(int n){
        int count = 0;
        while(n != 0){
            ++count;
            n = n & (n -1);
        }
        return count;
    }

    public static void main(String[] args) {
        System.out.println(numberOf1_best(5));
    }
}
