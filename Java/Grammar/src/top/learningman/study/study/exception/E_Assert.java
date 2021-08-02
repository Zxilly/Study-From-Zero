package top.learningman.study.study.exception;

public class E_Assert {
    public static void main(String[] args) {
        double x = Math.abs(-123.45);
        assert false; // 需要 -ea 以启用断言
        assert x >= 0 : "x must >= 0";
        System.out.println(x);
    }
}
