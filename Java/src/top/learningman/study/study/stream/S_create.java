package top.learningman.study.study.stream;

import java.util.stream.Stream;

/*
Stream提供的常用操作有：

转换操作：map()，filter()，sorted()，distinct()；

合并操作：concat()，flatMap()；

并行处理：parallel()；

聚合操作：reduce()，collect()，count()，max()，min()，sum()，average()；

其他操作：allMatch(), anyMatch(), forEach()。
 */

public class S_create {
    public static void main(String[] args) {
        Stream<String> stream = Stream.of("A", "B", "C", "D");
        // forEach()方法相当于内部循环调用，
        // 可传入符合Consumer接口的void accept(T t)的方法引用：
        stream.forEach(System.out::println);
    }
}
