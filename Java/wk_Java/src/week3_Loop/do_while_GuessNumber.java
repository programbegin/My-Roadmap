package week3_Loop;

import java.util.Scanner;

public class do_while_GuessNumber {
    public static void main(String argus[]){
        Scanner in = new Scanner(System.in);

        int randNumber= (int) (Math.random()*100+1);//[0,1)-->[0,100)-->[1,100]
        int guessNumber;
        int count=0;
        do {
            guessNumber=in.nextInt();
            if (guessNumber< randNumber){
                System.out.println("more small");
            }else if (guessNumber>randNumber){
                System.out.println("more big");
            }
            count++;
        }while(guessNumber!=randNumber);
        System.out.println("Congratulations, you're correct! You have guessed it "+count+" times");
    }
}
