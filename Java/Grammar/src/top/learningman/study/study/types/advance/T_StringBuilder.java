package top.learningman.study.study.types.advance;



public class T_StringBuilder {
    public static void main(String[] args) {
        StringBuilder a = new StringBuilder(10);
        for (int i = 0; i < 10000; i++) {
            var letter = (char)(Math.random()*26+'a');
            a.append(letter);
        }
        System.out.println(a.indexOf("z"));
        System.out.println(a.length());
        a.setLength(20);
        System.out.println(a);
    }
}
