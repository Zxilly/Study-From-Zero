package top.learningman.study.study.object;

public class o_implement implements o_interface{
    @Override
    public void a() {
        System.out.println("A");
    }

    @Override
    public void a_same() {
        System.out.println("A");
        System.out.println(b);
    }
}
