package top.learningman.study.study.object;

import top.learningman.study.Utils;

public class O_interface_default {
    public static void main(String[] args) {
        Person p = new Student("Xiao Ming");
        p.run();
    }
}

interface Person {
    String getName();
    default void run() {
        System.out.println(getName() + " run");
    }

    default void func() {
        Utils.Println("This is a default func.");
        // default 用于在接口中包含实现
        // 用于修改接口的同时，无需修改其子类（实现类）
        // 优先级低，会被 extends 继承的类覆盖
    }
}

class Student implements Person {
    private final String name;

    public Student(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }
}