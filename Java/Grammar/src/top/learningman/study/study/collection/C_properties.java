package top.learningman.study.study.collection;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.Properties;

public class C_properties {
    public static void main(String[] args) throws IOException {
        String settings = """
                # test
                course=Java
                last_open_date=2019-08-07T12:35:01""";
        ByteArrayInputStream input = new ByteArrayInputStream(settings.getBytes(StandardCharsets.UTF_8));
        Properties props = new Properties();
        props.load(input);

        System.out.println("course: " + props.getProperty("course"));
        System.out.println("last_open_date: " + props.getProperty("last_open_date"));
        System.out.println("last_open_file: " + props.getProperty("last_open_file"));
        System.out.println("auto_save: " + props.getProperty("auto_save", "60"));
    }
}
