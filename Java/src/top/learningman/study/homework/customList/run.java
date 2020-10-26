package top.learningman.study.homework.customList;

public class run {
    public static void main(String[] args){
        customList l=new customList(1, 2, 3, 4, 5, 6);
        for (int i=2;i<=10;i++){
            l.cPush(new customListNode(i));
        }
        l.cInsert(2,new customListNode(200));
        System.out.println(l.toString());
        customListNode a = l.cPop();
        System.out.println(l.toString());
        l = l.reverse();
        System.out.println(l.toString());
    }
}
