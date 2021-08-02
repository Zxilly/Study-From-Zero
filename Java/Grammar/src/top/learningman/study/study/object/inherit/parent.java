package top.learningman.study.study.object.inherit;

public class parent {
    public int day;
    public int month;

    public parent(int arg){
        this.day = 0;
        this.month = 0;
        System.out.println("test");
    }

    public parent(int day,int month) {
        this.day = day;
        this.month = month;
    }

    public void output(){
        System.out.println(Integer.toString(this.day)+Integer.toString(this.month));
    }
}
