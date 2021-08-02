package top.learningman.study.study.object.inherit;

public final class final_child extends parent {
    final int arg; //对象创建时确定，不可修改

    public final_child() {
        super(20);
        this.arg = 20;
    }
}
