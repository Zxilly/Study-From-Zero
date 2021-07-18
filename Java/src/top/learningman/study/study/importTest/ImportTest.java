package top.learningman.study.study.importTest;

import java.text.Format;
import java.text.MessageFormat; // ignore this can lead to Error
import java.lang.*;

public class ImportTest {

    public static class Main {
        public static void main(String[] args) {
            java.util.ArrayList<String> list; // ok，使用完整类名 -> java.util.List
            Format format = null; // ok，使用import的类 -> java.text.Format
            String s = "hi"; // ok，使用java.lang包的String -> java.lang.String
            System.out.println(s); // ok，使用java.lang包的System -> java.lang.System
            MessageFormat mf = null; // 编译错误：无法找到MessageFormat: MessageFormat cannot be resolved to a type
        }
    }
}
