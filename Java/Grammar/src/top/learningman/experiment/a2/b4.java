package top.learningman.experiment.a2;

import java.util.ArrayList;

public class b4 {
    static boolean[] check = new boolean[1001];
    static ArrayList<Integer> prime = new ArrayList<>();


    public static void main(String[] args) {
        for (int i = 0; i <= 1000; i++) {
            check[i] = true;
        }

        for (int i = 2; i <= 1000; i++) {
            if (check[i]) {
                prime.add(i);
            }

            for (int j = 0; j < prime.size() && i * prime.get(j) <= 1000; j++) {
                check[i * prime.get(j)] = false;
                if (i % prime.get(j) == 0) {
                    break;
                }
            }
        }

        for (int out : prime) {
            System.out.print(out + " ");
        }
        System.out.print("\n");
        System.out.println(prime.size());
    }
}
