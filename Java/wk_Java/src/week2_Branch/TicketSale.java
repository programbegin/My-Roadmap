package week2_Branch;

import java.util.Scanner;

public class TicketSale {
    public static void main(String[] args) {
        double a = 1.0;
        double b = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;
        System.out.println(a == b);
        System.out.println("a = " + a + "; b =" + b);
//        判断两数相等的常用方法
        System.out.println(Math.abs(a - b) < 1e-6);


//      初始化
        Scanner in = new Scanner(System.in);

        int amount = in.nextInt();
        System.out.println("请投币：");
        System.out.println(amount);
        System.out.println(amount >= 10);
//        打印车票
        if (amount >= 10) {
            System.out.println("**************************");
            System.out.println("*    Java 城际铁路专线   *");
            System.out.println("*      无指定座位票      *");
            System.out.println("*        票价十元        *");
            System.out.println("**************************");
//      计算并打印找零
            System.out.println("找零：" + (amount - 10));
        }
    }
}
