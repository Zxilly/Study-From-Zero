package top.learningman.study.study.operators;

public class StringPlus {
    public static void main(String[] args){
        String a = "test1";
        String b = "test2";
        System.out.println(a+b);
        a+=b;
        System.out.println(a);

        int x=0;
        System.out.println(""+x);
        System.out.println(Integer.toString(x));
        Integer y = new Integer(66);
        String z = y.toString();
    }
}
