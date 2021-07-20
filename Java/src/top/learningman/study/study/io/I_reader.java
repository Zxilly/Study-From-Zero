package top.learningman.study.study.io;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;

public class I_reader {
    public static void main(String[] args) {
        Reader reader = null;
        try {
            reader = new FileReader("src/top/learningman/study/study/io/I_file.java");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            System.exit(1);
        }
        for (;;) {
            int n = 0; // 反复调用read()方法，直到返回-1
            try {
                n = reader.read();
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (n == -1) {
                break;
            }
            System.out.print((char)n); // 打印char
        }
        try {
            reader.close(); // 关闭流
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
