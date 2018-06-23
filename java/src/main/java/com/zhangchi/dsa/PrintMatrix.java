package com.zhangchi.dsa;

import java.util.ArrayList;
import java.util.Iterator;

/**
 * 顺时针打印矩阵
 * @author Chi Zhang
 * @date 2018/1/30
 */
public class PrintMatrix {

    // 方法一,参考《剑指Offer》解法
    public ArrayList<Integer> printMatrix(int [][] matrix) {
        ArrayList<Integer> result = new ArrayList<>();
        if (matrix == null)
            return result;

        int rows = matrix.length;  // 行数
        int columns = 0;
        if(rows > 0)
            columns = matrix[0].length;   // 列数
        else
            return result;

        int start = 0;
        while(columns > start * 2 && rows > start * 2){
            printMatrixInCircle(matrix, rows, columns, start, result);
            ++start;
        }

        return result;
    }

    // 方法二，个人解法，通俗易懂
    public ArrayList<Integer> printMatirx1(int[][] matrix){
        ArrayList<Integer> result = new ArrayList<Integer>();

        int rows = matrix.length;
        if(rows == 0)
            return result;

        int columns = matrix[0].length;
        int startX = 0, endX = columns - 1;
        int startY = 0, endY = rows - 1;

        while (startX <= endX && startY <= endY){
            // 从左往右
            for(int i = startX; i <= endX; ++i)
                result.add(matrix[startY][i]);

            // 从上往下
            if(startY + 1 > endY)
                break;
            for(int i = startY + 1; i <= endY; ++i)
                result.add(matrix[i][endX]);

            // 从右往左
            if(endX - 1 < startX)
                break;
            for(int i = endX - 1; i >= startX; --i)
                result.add(matrix[endY][i]);

            // 从下往上
            if(endY - 1 <= startY)
                break;
            for(int i = endY - 1; i > startY; --i)
                result.add(matrix[i][startX]);

            ++startX;
            ++startY;
            --endX;
            --endY;
        }

        return result;
    }

    private void printMatrixInCircle(int[][] matrix,int rows, int columns, int start,ArrayList<Integer> printList){
        int endX = columns - 1 - start;
        int endY = rows - 1 - start;

        // 从左到右打印一行
        for (int i = start; i <= endX; ++i)
            printList.add(matrix[start][i]);

        // 从上到下打印一列
        if(start < endY){
            for (int i = start + 1; i <= endY; ++i)
                printList.add(matrix[i][endX]);
        }

        // 从右到左打印一行
        if(start < endX && start < endY){
            for (int i = endX - 1; i >= start; --i)
                printList.add(matrix[endY][i]);
        }

        // 从下到上打印一列
        if(start < endX && start < endY - 1){
            for (int i = endY - 1; i >= start + 1; --i)
                printList.add(matrix[i][start]);
        }

    }

    public static void print(ArrayList<Integer> arrayList){
        for (Iterator it = arrayList.iterator(); it.hasNext();)
            System.out.print(it.next() + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        int[][] matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
        print(new PrintMatrix().printMatirx1(matrix));
    }
}
