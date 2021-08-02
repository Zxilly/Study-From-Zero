package top.learningman.study.study.types.advance;

import org.jetbrains.annotations.Contract;

public class T_Record {
    public static void main(String[] args) {
        var a = Point.of();
        var b = new Point(2, 3);
        var c = new Point(200, 4);
    }

    public record Point(int x, int y) {
        public Point {
            if (x > 20) {
                throw new IllegalArgumentException("WTF are you helling doing?");
            }
        }

        @Contract(value = " -> new", pure = true)
        public static Point of() {
            return new Point(2, 3);
        }
    }
}
