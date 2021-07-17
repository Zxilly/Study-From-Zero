package top.learningman.experiment.a2;

import java.util.*;

public class b5 {
    static Scanner in = new Scanner(System.in);

    static boolean isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

    static int getMonthDays(boolean isLeapYear, int month) {
        if (month == 2 && isLeapYear) {
            return 29;
        } else if (month == 2) {
            return 28;
        } else if (Arrays.binarySearch(new int[]{4, 6, 9, 11}, month) < 0) {
            return 31;
        } else {
            return 30;
        }
    }

    static int getYearDays(int year) {
        int totalDays = year * 365 + year / 4 - year / 100 + year / 400;
        int startDays = 1900 * 365 + 1900 / 4 - 1900 / 100 + year / 400;
        return totalDays - startDays;
    }

    static int getMonthDaysInYear(boolean isLeapYear, int month) {
        int result = 0;
        for (int i = 1; i < month; i++) {
            result += getMonthDays(isLeapYear, i);
        }
        return result;
    }

    static void drawCalendar(int year, int month) {
        int allDays = getYearDays(year) + getMonthDaysInYear(isLeapYear(year), month) + 1;
        // System.out.println(allDays);
        int startWeekDay = allDays % 7;
        int weekDay;
        if(startWeekDay==0){
            weekDay = 7;
            startWeekDay = 7;
        } else {
            weekDay = startWeekDay;
        }
        System.out.println("一\t二\t三\t四\t五\t六\t日");
        for (int i = 1; i < startWeekDay; i++) {
            System.out.print("\t");
        }
        for (int i = 1; i <= getMonthDays(isLeapYear(year), month); i++) {
            System.out.print(i + "\t");
            if (weekDay == 7) {
                System.out.print("\n");
                weekDay = 1;
            } else {
                weekDay++;
            }
        }
    }

    public static void main(String[] args) {
        System.out.println("请输入年月，用空格分隔：");
        drawCalendar(in.nextInt(), in.nextInt());
    }
}
