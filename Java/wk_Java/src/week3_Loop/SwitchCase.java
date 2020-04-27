package week3_Loop;

import java.util.Scanner;

public class SwitchCase {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int type;
        type = in.nextInt();
        switch (type) {
            case 1:
            case 2:
                System.out.println("Hello!");
                break;
            case 3:
                System.out.println("Good Evening!");
            case 4:
                System.out.println("Good Bey!");
                break;
            default:

        }

    }
}
