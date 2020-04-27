package week2_Branch;

import java.util.Scanner;

public class OvertimePay {
    public static void main(String[] args) {
        final double RATE = 8.25;
        final double STANDARD = 40;
        double pay = 0.0;
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the number of hours worked: ");
        int hours = in.nextInt();
        System.out.println();
        if (hours > STANDARD)
            pay = STANDARD * RATE + (hours - STANDARD) * (RATE * 1.5);
        else
            pay = hours * RATE;
        System.out.println("Gross earnings:" + pay);
    }
}
