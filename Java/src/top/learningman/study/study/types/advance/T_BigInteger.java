package top.learningman.study.study.types.advance;

import java.math.BigInteger;

public class T_BigInteger {
    public static void main(String[] args) {
        BigInteger n = new BigInteger("999999").pow(99);
        float f = n.floatValue();
        System.out.println(f);
    }
}
