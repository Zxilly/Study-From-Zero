package top.learningman.study.homework.customList;

public class run {
    public static void main(String[] args){
        customList l=new customList(1);
        for (int i=1;i<=10;i++){
            l.cPush(new customListNode(i));
        }
        l.cPrint();
    }
}
