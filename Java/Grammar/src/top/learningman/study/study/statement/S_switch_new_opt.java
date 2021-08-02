package top.learningman.study.study.statement;

import java.util.Scanner;

public class S_switch_new_opt {
    public static void main(String[] args) {
        var a = new Scanner(System.in).nextLine();

        var b = switch (a){
            case "test" -> {
                System.out.println("Side Effect");
                yield 40;
            }
            case "str" -> 20;
            default -> throw new IllegalStateException("Unexpected value: " + a);
        };

        System.out.println(b);
    }
}
