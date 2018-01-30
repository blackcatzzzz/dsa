package com.zhangchi.dsa;

/**
 * 字符串转int
 * 参考：
 * 1.http://blog.csdn.net/Evan123mg/article/details/45459781
 * 2.Integer.parseInt(String s) 源码
 * @author Chi Zhang
 * @date 2018/1/30
 */
public class StringToInt {

    public static int parseInt(String s) throws MyException {
        if (s == null)
            throw new MyException("字符串为null！");

        int len  = s.length();
        int i = 0;
        boolean negative = false;
        int result = 0, digit;

        if (len > 0){
            char firstChar = s.charAt(i);
            if (firstChar < '0'){
                if (firstChar == '-')
                    negative = true;
                else if(firstChar != '+')
                    throw new MyException("第一个字符非法！");

                if (len == 1)
                    throw new MyException("字符串非法！");
                ++i;
            }

            int limit = Integer.MAX_VALUE / 10;
            while (i < len){
                char ch = s.charAt(i);
                if ('0' <= ch && ch <= '9'){
                    digit = ch - '0';

                    if (result == limit && ( (!negative && digit > 7) || (negative && digit > 8) ))
                        throw new MyException("溢出！");
                    else if (result > limit)
                        throw new MyException("溢出！");

                    result = result * 10 + digit;

                    ++i;
                }else {
                    throw new MyException("字符串非法！");
                }
            }

        }else{
            throw new MyException("字符串长度为0！");
        }

        return result;
    }

    public static void main(String[] args) {
        String s1 = "123456";
        String s2 = "2147483648"; // 溢出
        String s3 = "-2147483648";
        String s4 = "-2147483649"; // 溢出
        int max = Integer.MAX_VALUE; // 2147483647
        int min = Integer.MIN_VALUE; // -2147483648
        System.out.println("Integer.MAX_VALUEL: " + max);
        System.out.println("Integer.MIN_VALUE: " + min);

        try{
            System.out.println("parseInt(" + s4 + "): " + StringToInt.parseInt(s4));
        }catch (MyException e){
            System.out.println(e.getMessage());
        }
    }
}

class MyException extends Exception{
    private String message;

    public MyException(String message) {
        this.message = message;
    }

    @Override
    public String getMessage() {
        return message;
    }
}
