package week3_Loop;

import java.util.Scanner;

public class while_Count {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int number=0;
        int sum = 0;
        int count = 0;
//        number = in.nextInt();
//        while (number != -1) {
//            sum = sum + number;
//            count = count + 1;
//            number = in.nextInt();
//        }
        do {
            number = in.nextInt();
            if (number != -1) {
                sum = sum + number;
                count = count + 1;
            }
        } while (number != -1);

        if (count > 0) {
            System.out.println("平均数 = " + (double) sum / count);
        }
    }
}
