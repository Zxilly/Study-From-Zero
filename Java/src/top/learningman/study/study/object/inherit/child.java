package top.learningman.study.study.object.inherit;

public class child extends parent{
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
