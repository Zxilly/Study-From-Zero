package top.learningman.experiment.a4;

import java.util.HashMap;
import java.util.Map;

public class b1 {
    static int[] my_array = {1, 2, 5, 5, 6, 6, 7, 2, 9, 2};

    public static void main(String[] args) {
        Map<Integer, Integer> temp = new HashMap<>();
        for (int j : my_array) {
            // System.out.println(j);
            temp.merge(j, 1, Integer::sum);
        }
        // System.out.println("2333");
        for (int i = 1; i <= 10; i++) {
            if (temp.get(i) != null && temp.get(i) > 1) {
                System.out.println(i);
            }
        }
    }
}
