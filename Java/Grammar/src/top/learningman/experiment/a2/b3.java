package top.learningman.experiment.a2;

import java.util.Scanner;

public class b3 {
    static int[] primeList = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
    static int[] result = new int[100];
    static int resultPointer = 0;
    static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        int input = in.nextInt();
        while (input != 1) {
            for (int prime : primeList) {
                if (input % prime == 0) {
                    result[resultPointer] = prime;
                    resultPointer++;
                    input /= prime;
                    break;
                }
            }
        }
        for (int i = 1; i < resultPointer; i++) {
            System.out.print(result[i] + " ");
        }
    }
}
