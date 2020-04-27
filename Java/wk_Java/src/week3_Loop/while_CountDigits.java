package week3_Loop;

import java.util.Scanner;

public class while_CountDigits {
    public static void main(String[] argus) {
        Scanner in = new Scanner(System.in);
        int number = in.nextInt();
        int initNum = number;
        int count = 0;

//        while (number > 0) {
//            //正整数已经可以正确判断，但是测试数据为0则发生错误
//            number /= 10;
//            count++;
//        }

        do {
            //采用do_while循环解决测试数据为0的情况
            number /= 10;
            count++;
        } while (number > 0);


        System.out.println(initNum + "是" + count + "位数");
    }
}
