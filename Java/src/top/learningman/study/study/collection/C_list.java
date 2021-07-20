package top.learningman.study.study.collection;

import java.util.ArrayList;
import java.util.List;

public class C_list {
    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>();

        List<Integer> list2 = new ArrayList<>(List.of(1, 2, 5));

        Class<? extends List> cls = list2.getClass();
        System.out.println(cls.getName());
        System.out.println(cls.getSimpleName());
        System.out.println(cls.getPackageName());

        list2.add(20);
        System.out.println(list2.get(1));
    }
}
