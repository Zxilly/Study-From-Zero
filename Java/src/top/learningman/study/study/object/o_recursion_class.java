package top.learningman.study.study.object;

public class o_recursion_class {
    public class oneclass {
        public class twoclass {
            public class threeclass {
                public threeclass() {
                    System.out.println("OK");
                }
            }
        }
    }
}

class o_rec2 {
    public static void main(String[] args) {
        o_recursion_class.oneclass.twoclass.threeclass a = new o_recursion_class().new oneclass().new twoclass().new threeclass();
    }
}