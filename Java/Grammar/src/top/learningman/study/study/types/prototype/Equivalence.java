package top.learningman.study.study.types.prototype;

public class Equivalence {
    public static void main (String[] args){
        int n1 = 100;
        Integer n2 = new Integer(100);
        Integer n3 = new Integer(100);
        boolean ba = n1 == n2;
        boolean bb = n2 == n3;
        boolean bc = n1 == n3;

        System.out.println(ba);
        System.out.println(bb);
        System.out.println(bc);
    }
}
