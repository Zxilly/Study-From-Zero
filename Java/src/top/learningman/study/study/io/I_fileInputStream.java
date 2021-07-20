package top.learningman.study.study.io;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

public class I_fileInputStream {
    public static void main(String[] args) throws IOException {
        // 创建一个FileInputStream对象:
        try (InputStream input = new FileInputStream("C:\\Study\\Code\\Java\\src\\top\\learningman\\study\\study\\io\\I_file.java")) {
            // try-resource 要求对象实现 java.lang.AutoCloseable 接口
            int n;
            while ((n = input.read()) != -1) { // 利用 while 同时读取并判断， read 是阻塞的
                System.out.print((char)n);
            }
        }
    }
}
