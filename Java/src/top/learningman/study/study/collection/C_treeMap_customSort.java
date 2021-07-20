package top.learningman.study.study.collection;

import java.util.Comparator;
import java.util.Map;
import java.util.TreeMap;

public class C_treeMap_customSort {
    public static void main(String[] args) {
        Map<Person, Integer> map = new TreeMap<>(Comparator.comparing(p -> p.name));
        map.put(new Person("Tom"), 1);
        map.put(new Person("Bob"), 2);
        map.put(new Person("Lily"), 3);
        for (Person key : map.keySet()) {
            System.out.println(key);
        }
        // {Person: Bob}, {Person: Lily}, {Person: Tom}
        System.out.println(map.get(new Person("Bob"))); // 2
    }
    static class Person implements Comparator<Person>{
        public String name;
        Person(String name) {
            this.name = name;
        }

        @Override
        public String toString() {
            return "{Person: " + name + "}";
        }

        @Override
        public int compare(Person o1, Person o2) {
            return o1.name.compareTo(o2.name);
        }
    }

}
