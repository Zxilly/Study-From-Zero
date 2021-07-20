package top.learningman.study.study.collection;

import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

public class C_set {
    public static void main(String[] args) {
        Set<String> set = new HashSet<>(); // 不保证有序
        set.add("apple");
        set.add("banana");
        set.add("pear");
        set.add("orange");
        for (String s : set) {
            System.out.println(s);
        }

        Set<String> set2 = new TreeSet<>(); // 保证有序
        // 添加的元素必须正确实现 Comparable 接口，如果没有实现 Comparable 接口，那么创建 TreeSet 时必须传入一个 Comparator 对象

        set2.add("apple");
        set2.add("banana");
        set2.add("pear");
        set2.add("orange");
        for (String s : set2) {
            System.out.println(s);
        }
    }
}
