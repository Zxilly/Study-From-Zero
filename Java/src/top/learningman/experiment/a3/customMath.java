package top.learningman.experiment.a3;

import java.util.Random;

public class customMath {
    public static final double PI = 3.1415926535;

    public static char randomUpperCaseChar() {
        int i = new Random().nextInt(26) + 'A';
        return (char) i;
    }

    public static double sqrt(double a) {
        double error = 1e-5;
        double root0 = 1;
        double root1 = 1.0 / 2 * (root0 + a / root0);
        while (Math.abs(root1 - root0) >= error) {
            root0 = root1;
            root1 = 1.0 / 2 * (root0 + a / root0);
        }
        return root1;
    }

    public static double cos(int degree){
        double x = PI/180*degree;
        double result = 1;
        int flag = -1;
        for(int n=2;n<=20;n+=2){
            result = result + flag*Math.pow(x,n)/factorial(n);
            flag*=-1;
        }
        return result;
    }

    public static int factorial(int num){
        int result = 1;
        for(int i=1;i<=num;i++){
            result*=i;
        }
        return result;
    }

    public static void main(String[] args){
        System.out.println(customMath.cos(60));
    }
}
