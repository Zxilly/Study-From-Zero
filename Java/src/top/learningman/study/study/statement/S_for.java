package top.learningman.study.study.statement;

import top.learningman.study.Utils;

import java.util.Arrays;

public class S_for {
    public static void main(String[] args) {
        for (int i = 1; i < 5; i++) {
            for (int j = 1; j < 5; j++) {
                System.out.println("A");
                if (j == 2) {
                    break;
                }
            }
            System.out.println("B");
        }

        System.out.println("-------------------------");

        outer:
        for (int i = 1; i < 5; i++) {
            for (int j = 1; j < 5; j++) {
                System.out.println("A");
                if (j == 2) {
                    break outer;
                }
            }
            System.out.println("B");
        }

        Utils.Println("-------------------------------");

        int[] a = {2, 3, 4, 5, 6, 7, 8};
        for (int i : a) {
            System.out.println(i);
        }

        Utils.Println("-------------------------------");

        int[] aa = {2, 3, 4, 5, 6, 7, 8};
        System.out.println(Arrays.toString(aa));

        Utils.Println("-------------------------------");

        int[][][] ns = {
                {
                        {1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}
                },
                {
                        {10, 11},
                        {12, 13}
                },
                {
                        {14, 15, 16},
                        {17, 18}
                }
        };
        System.out.println(Arrays.deepToString(ns));
    }
}
