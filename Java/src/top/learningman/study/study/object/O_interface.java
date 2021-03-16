package top.learningman.study.study.object;

public interface O_interface {
    void a();
    public abstract void a_same(); //等价，同时冗余

    int b = 0;
    public static final int b_same = 0; //等价，同时冗余

}
