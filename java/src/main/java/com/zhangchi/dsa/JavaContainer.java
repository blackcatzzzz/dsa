package com.zhangchi.dsa;


import java.util.*;

public class JavaContainer {

    private final Integer i = 1;

    JavaContainer(){
        //i = 1;
    }

    public static void main(String[] args){
        LinkedList<Integer> linkedList = new LinkedList<>();
        linkedList.add(1);
        linkedList.add(2);
        linkedList.add(1,0);

        Iterator<Integer> it = linkedList.iterator();
        System.out.print("linkedList: ");
        while(it.hasNext())
            System.out.print(it.next() + " ");
        System.out.println();

        linkedList.remove(0);
        linkedList.add(0, 1);
        System.out.println("index(1), " + linkedList.get(1));

        String s1 = "hello world";
        System.out.print(s1.substring(0, 2));
        ArrayList<String> list = new ArrayList<String>(Arrays.asList("a","b","c","d"));
        for(String s:list){
            if(s.equals("a")){
                list.remove(s);
            }
        }
        //HashMap
        //Collection;
        //Stack;
        //Queue;
    }
}

//
//interface A{
//    void funA();
//}
//
//interface B{
//    void funB();
//}
//
//interface C extends A , B{
//
//}
//
//class D implements C{
//    public void funB(){};
//    public void funA(){};
//}