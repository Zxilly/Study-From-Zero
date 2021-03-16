package top.learningman.study.study.object;

public class O_implement implements O_interface {
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
