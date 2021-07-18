package top.learningman.study.study.types.advance;

public class T_CharArray {
    public static void main(String[] args) {
        char[] cs = "Hello".toCharArray();
        String s = new String(cs);
        System.out.println(s);
        System.out.println(cs);
        cs[0] = 'X';
        char[] css = cs.clone();
        System.out.println(cs);
    }
}
