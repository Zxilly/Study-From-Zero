package top.learningman.study.study.types.prototype;

import static top.learningman.study.Utils.Println;

import java.util.Arrays;

class Array {
    public static void main(String[] args) {
        int[] array = {1, 2, 3, 4, 5};
        Println(Arrays.toString(array));
    }
}

class ArraySort {
    public static void main(String[] args) {
        int[] ns = {28, 12, 89, 73, 65, 18, 96, 50, 8, 36};
        Arrays.sort(ns);
        Println(Arrays.toString(ns));
    }
}