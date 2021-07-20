package top.learningman.study.study.io;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.nio.charset.StandardCharsets;

public class I_outputStream {
    public static void main(String[] args) {
        File tempFile = null;
        try {
             tempFile = File.createTempFile("tmp-",".txt");
             tempFile.deleteOnExit();
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            assert tempFile != null;
            try (OutputStream output = new FileOutputStream(tempFile)) {
                output.write("Hello".getBytes(StandardCharsets.UTF_8)); // Hello

            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
