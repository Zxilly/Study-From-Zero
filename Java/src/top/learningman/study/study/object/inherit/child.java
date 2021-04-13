package top.learningman.study.study.object.inherit;

public class child extends parent{
    public child() {
        super(20);
    }

    // 如果父类没有默认的构造方法，子类就必须显式调用 super() 并给出参数以便让编译器定位到父类的一个合适的构造方法。

    @Override
    public void output(){
        System.out.println("son");
    }


    public static void main(String[] args){
        child entity = new child();
        entity.output();
//        parent entity2 = new parent(2,3);
//        entity2.output();
    }
}
