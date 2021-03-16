package top.learningman.study.study.statement;

import java.util.Scanner;

public class S_switch_new {
    public static void main(String[] args) {
        var a = new Scanner(System.in).nextInt();
        switch (a) {
            case 2 -> {
                System.out.println("two");
            }
            case 3 -> {
                System.out.println("three");
            }
            default -> {
                System.out.println("default");
            }
        }
    }
}
