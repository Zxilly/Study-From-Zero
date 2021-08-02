package top.learningman.study.study.exception;

import java.io.UnsupportedEncodingException;
import java.util.Arrays;

public class E_TryCatch {
    public static void main(String[] args) {
        byte[] bs = toGBK();
        System.out.println(Arrays.toString(bs));
    }

    @SuppressWarnings("all")
    static byte[] toGBK() {
        try {
            // 用指定编码转换 String 为 byte[]:
            return "中文".getBytes("GBKKKK");
        } catch (UnsupportedEncodingException e) {
            // 如果系统不支持 GBK 编码，会捕获到 UnsupportedEncodingException:
            e.printStackTrace(); // 打印异常信息
            return "中文".getBytes(); // 尝试使用用默认编码
        }
    }
}
