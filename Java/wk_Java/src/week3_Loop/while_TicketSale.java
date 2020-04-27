package week3_Loop;

import java.util.Scanner;

public class while_TicketSale {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int balance = 0;
//        输入投币金额
        while (true) {
            System.out.println("请投币：");
            int amount = in.nextInt();
            balance = balance + amount;
            if (balance >= 10) {

                System.out.println("****************");
                System.out.println("* 城际铁路专线 *");
                System.out.println("* 无指定座位票 *");
                System.out.println("*   票价10元   *");
                System.out.println("****************");
//            计算并打印找零
                System.out.println("找零" + (balance - 10));
                balance =0;
            }
        }
    }

}
