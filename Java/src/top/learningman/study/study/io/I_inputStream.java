package top.learningman.study.study.io;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;

public class I_inputStream {
    public static void main(String[] args) throws IOException {
        byte[] data = { 72, 101, 108, 108, 111, 33 };
        try (InputStream input = new ByteArrayInputStream(data)) {
            // 应当实现 InputStream， 根据需求挑选具体的实现类
            String s = readAsString(input);
            System.out.println(s);
        }
    }

    public static String readAsString(InputStream input) throws IOException {
        int n;
        StringBuilder sb = new StringBuilder();
        while ((n = input.read()) != -1) {
            sb.append((char) n);
        }
        return sb.toString();
    }
}
