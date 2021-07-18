package top.learningman.study.study.types.advance;

public class T_StringFormat {
    public static void main(String[] args) {
        String s = "Hi %s, your score is %d!";
        var b = String.format("Hi %s, your score is %.2f!", "Bob", 59.5);
        System.out.printf((s) + "%n", "Alice", 80);
        System.out.println(b);
    }
}
