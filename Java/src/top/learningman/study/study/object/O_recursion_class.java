package top.learningman.study.study.object;

public class O_recursion_class {
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
        O_recursion_class.oneclass.twoclass.threeclass a = new O_recursion_class().new oneclass().new twoclass().new threeclass();
    }
}