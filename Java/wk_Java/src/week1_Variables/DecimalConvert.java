package week1_Variables;

import java.util.Scanner;

public class DecimalConvert {
    public static void main(String[] args) {
        //设计变量
        int foot;
//            int inch;
        double inch;
        //获取用户数据
        Scanner in = new Scanner(System.in);
        foot = in.nextInt();
        inch = in.nextInt();

        //操作输出
//        System.out.println(10/3);
//        System.out.println(1.2 - 1.1);
        System.out.println((int) ((foot + inch / 12) * 0.3048 * 100) + " CM");

    }
}
