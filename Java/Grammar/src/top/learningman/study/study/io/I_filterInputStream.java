package top.learningman.study.study.io;

import org.jetbrains.annotations.NotNull;

import java.io.ByteArrayInputStream;
import java.io.FilterInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.nio.charset.StandardCharsets;

public class I_filterInputStream {
    public static void main(String[] args) throws IOException {
        byte[] data = "hello, world!".getBytes(StandardCharsets.UTF_8);
        try (CountInputStream input = new CountInputStream(new ByteArrayInputStream(data))) {
            int n;
            while ((n = input.read()) != -1) {
                System.out.print((char)n);
            }
            System.out.println("\nTotal read " + input.getBytesRead() + " bytes");
        }
    }
    static class CountInputStream extends FilterInputStream {
        private int count = 0;

        CountInputStream(InputStream in) {
            super(in);
        }

        public int getBytesRead() {
            return this.count;
        }

        public int read() throws IOException {
            int n = in.read();
            if (n != -1) {
                this.count ++;
            }
            return n;
        }

        public int read(byte @NotNull [] b, int off, int len) throws IOException {
            int n = in.read(b, off, len);
            if (n != -1) {
                this.count += n;
            }
            return n;
        }
    }
}
