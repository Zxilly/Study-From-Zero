package top.learningman.study.study.collection;

import java.util.HashMap;
import java.util.Map;

public class C_map {
    static class Student {
        public String name;
        public int score;

        public Student(String name, int score) {
            this.name = name;
            this.score = score;
        }
    }

    public static void main(String[] args) {
        Student s = new Student("Xiao Ming", 99);
        Map<String, Student> map = new HashMap<>();
        map.put("Xiao Ming", s); // 将 "Xiao Ming" 和 Student 实例映射并关联
        Student target = map.get("Xiao Ming"); // 通过 Key 查找并返回映射的 Student 实例
        System.out.println(target == s); // true 同一个实例
        System.out.println(target.score); // 99
        Student another = map.get("Bob"); // 通过另一个 Key 查找
        System.out.println(another); // 未找到返回 null
    }
}
