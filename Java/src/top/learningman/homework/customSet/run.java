package top.learningman.homework.customSet;

public class run {
    public static void main(String[] args){
        customSet a = new customSet();
        customSet b = new customSet();

        System.out.println("生成两个集合");

        for(int i=1;i<=10;i++){
            a.add(i);
        }

        for(int i=6;i<=15;i++){
            b.add(i);
        }

        a.print();
        b.print();

        new customSet();
        customSet c;
        c = customSetOperator.union(a,b);
        System.out.println("并集");
        c.print();
        c = customSetOperator.intersection(a,b);
        System.out.println("交集");
        c.print();

    }
}
