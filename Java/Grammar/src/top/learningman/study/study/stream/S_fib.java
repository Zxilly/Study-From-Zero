package top.learningman.study.study.stream;

import java.util.stream.LongStream;

public class S_fib {
    static long a = 0;
    static long b = 1;
    public static void main(String[] args) {

        LongStream fibStream = LongStream.generate(()->{
            long tmp = a;
            a = b;
            b += tmp;
            return a;
        });
        fibStream.limit(80).forEach(System.out::println);
    }
}
