package top.learningman.study.study.statement;

import java.util.Scanner;

public class S_switch {
    public static void main(String[] args) {
        int a = new Scanner(System.in).nextInt();
        switch (a){
            case 1:
                System.out.println("one");
            case 2:
                System.out.println("two");
            case 3:
                System.out.println("three");
            default:
                System.out.println("default");
                break;
            case 4:
                System.out.println("four");
        }
    }
}
