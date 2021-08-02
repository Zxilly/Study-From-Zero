package top.learningman.experiment.a4;

import java.util.Random;

public class b3 {
    static Random rand = new Random();

    public static void main(String[] args) {
        char[] randstring = new char[100];
        for (int i = 0; i < randstring.length; i++) {
            randstring[i] = (char) ((rand.nextBoolean() ? 65 : 97) + rand.nextInt(26));
        }
        int count = 0;
        for (char j : randstring) {
            if ((int) j >= 97) {
                count++;
            }
        }
        System.out.println(randstring);
        System.out.println(count);
    }
}
