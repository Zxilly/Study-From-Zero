package top.learningman.study.homework;

import java.util.*;

public class rockPaperScissors {
    static Scanner reader = new Scanner(System.in);
    static Random rand = new Random(20201009);

    private static final Map<Integer, String> myMap;

    static {
        myMap = new HashMap<>();
        myMap.put(0, "石头");
        myMap.put(1, "剪刀");
        myMap.put(2, "布");
    }

    private static String judge(int aiChoice, int playerChoice) {
        if (
                (aiChoice == 0 && playerChoice == 1)
                        || (aiChoice == 1 && playerChoice == 2)
                        || (aiChoice == 2 && playerChoice == 0)
        ) {
            //AI胜
            return "你输了";
        } else if (aiChoice == playerChoice) {
            //平局
            return "平局";
        } else {
            //AI败
            return "你赢了";
        }
    }

    private static void rpsAI(int userChoice) {
        int rpsAIchoice = rand.nextInt(3);
        System.out.printf("你出了 %s，电脑出了 %s\n", myMap.get(userChoice), myMap.get(rpsAIchoice));
        System.out.println(judge(rpsAIchoice, userChoice));
    }

    public static void main(String[] args) {
        System.out.println("石头剪刀布（输入9退出）");
        System.out.println("石头：0，剪刀：1，布：2");
        while (true) {
            System.out.println("请出手势：");
            int input = reader.nextInt();
            switch (input) {
                case 0:
                case 1:
                case 2:
                    rpsAI(input);
                    break;
                case 9:
                    break;
                default:
                    System.out.println("输入不合法");
            }
            if (input == 9) {
                break;
            }
        }
    }
}
