package top.learningman.study.study.io;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.Arrays;

public class I_serializable {
    record Something(int aa, double bb) implements Serializable {
    }

    public static void main(String[] args) throws IOException {
        ByteArrayOutputStream buffer = new ByteArrayOutputStream();
        try (ObjectOutputStream output = new ObjectOutputStream(buffer)) {
            // 写入Object:
            try {
                output.writeObject(new Something(20, 33.1));
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        System.out.println(Arrays.toString(buffer.toByteArray()));
    }
}
