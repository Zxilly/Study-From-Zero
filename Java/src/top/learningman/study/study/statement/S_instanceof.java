package top.learningman.study.study.statement;

public class S_instanceof {

    public static void main(String[] args) {
        Object obj = "hello";
        if (obj instanceof String s) {
            // 可以直接使用变量s:
            System.out.println(s.hashCode());
            System.out.println(s.toUpperCase());
        }
    }


}
