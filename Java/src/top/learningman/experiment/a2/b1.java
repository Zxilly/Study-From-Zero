package top.learningman.experiment.a2;

import java.util.InputMismatchException;
import java.util.Scanner;

public class b1 {
    static Scanner reader = new Scanner(System.in);

    static void print (String input){
        System.out.println(input);
    }

    public static void main(String[] args){
        print("Input your mark.");
        int input = reader.nextInt();
        String grade = "";

        if(input >= 90){
            grade="A";
        } else if(input>=80){
            grade="B";
        }else if(input>=70){
            grade="C";
        }else if(input>=60){
            grade="D";
        }else if(input>=0){
            grade="E";
        }else{
            throw new InputMismatchException();
        }

        print("Your grade is "+grade);
    }
}
