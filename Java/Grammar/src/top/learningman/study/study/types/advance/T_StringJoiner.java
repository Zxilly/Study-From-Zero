package top.learningman.study.study.types.advance;

import java.util.StringJoiner;

public class T_StringJoiner {
    public static void main(String[] args) {
        String[] names = {"Bob", "Alice", "Grace"};
        var sj = new StringJoiner(", ", "Hello ", "!"); // 和 String.join() 一致，但是可以指定 prefix 和 suffix
        for (String name : names) {
            sj.add(name);
        }
        System.out.println(sj);
    }
}
