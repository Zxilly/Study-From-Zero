package top.learningman.study.experiment.a3;

import java.util.Random;

public class customMath {
    public static final double PI = 3.1415926535;

    public static char randomUpperCaseChar(){
        int i = new Random().nextInt(26)+'A';
        return (char)i;
    }

    public static double sqrt(double a){
        double error = 1e-5;
        double root0 = 1;
        double root1 = 1.0/2*(root0+a/root0);
        while(Math.abs(root1-root0)>=error){
            root0 = root1;
            root1 = 1.0/2*(root0+a/root0);
        }
        return root1;
    }
}
