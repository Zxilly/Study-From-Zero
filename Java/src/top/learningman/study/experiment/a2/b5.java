package top.learningman.study.experiment.a2;

import java.util.*;

public class b5 {
    static Scanner in = new Scanner(System.in);

    static boolean isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

    static int getMonthDays(int year, int month) {
        if (month == 2 && isLeapYear(year)) {
            return 29;
        } else if (month == 2) {
            return 28;
        } else if (Arrays.binarySearch(new int[]{4, 6, 9, 11}, month) < 0) {
            return 31;
        } else {
            return 30;
        }
    }


}
