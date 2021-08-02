package top.learningman.experiment.a6;

import java.util.HashMap;
import java.util.Map;

public class arraycount {
    static int[] testarray = {1,2,3,4,5,5,6,6,7,7,8,8};

    public static int count(int[] input){
        int count = 0;
        Map<Integer, Integer> temp = new HashMap<>();
        for (int i: input) {
            temp.merge(i, 1, Integer::sum);
        }
        for (int key:
             temp.keySet()) {
            if (temp.get(key)>1){
                count++;
            }
        }
        return count;
    }

    public static void main(String[] argv){
        System.out.println(count(testarray));
    }
}
