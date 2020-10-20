package top.learningman.study.homework;

public class bear {
    public static void main(String[] args) {
        int num = 1543;
        int count = 0;
        while (num != 0) {
            if (num % 2 == 1) {
                num = (num - 1) / 2;
                count++;
            } else {
                num = num / 2;
            }
        }
        System.out.println(count);
    }
}
