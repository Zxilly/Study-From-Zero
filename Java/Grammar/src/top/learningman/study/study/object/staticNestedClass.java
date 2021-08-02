package top.learningman.study.study.object;

public class staticNestedClass {
    public static class Main{
        public static void main(String[] args) {
            Outer.StaticNested sn = new Outer.StaticNested();
            sn.hello();
        }
    }

    static class Outer {
        private static final String NAME = "OUTER";

        static class StaticNested {
            void hello() {
                System.out.println("Hello, " + Outer.NAME);
            }
        }
    }
}

