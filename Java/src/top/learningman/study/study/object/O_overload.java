package top.learningman.study.study.object;

import top.learningman.study.Utils;

public class O_overload {
    public static int add(int a, int b) {
        return a + b;
    }

    public static double add(double a, double b) {
        return a + b;
    }
    // 根据参数

    public static void main(String[] args) {
        Utils.Println(add(2, 3));
        Utils.Println(add(2.2, 3.3));
    }
}
