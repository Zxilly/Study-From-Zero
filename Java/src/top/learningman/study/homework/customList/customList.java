package top.learningman.study.homework.customList;

public class customList {
    customListNode head;

    public customList(int data){
        this.head = new customListNode(data);
    }

    public void cGet(int n){
        customListNode tmp = this.head;
        for(int i=1;i<n;i++){
            tmp = tmp.getNext();
            assert tmp != null:"Index out of stack.";
        }
    }

    public void cInsert(int n, customListNode e){
        customListNode tmp = this.head;
        for(int i=1;i<n-1;i++){
            tmp = tmp.getNext();
        }
        e.setNext(tmp.getNext());
        tmp.setNext(e);
    }

    public void cPrint(){
        customListNode tmp = head;
        while(tmp.getNext()!=null){
            System.out.print(tmp.getData());
            System.out.print(" ");
            tmp=tmp.getNext();
        }
        System.out.print(tmp.getData());
        System.out.print(" ");
    }

    public void cPush(customListNode e){
        customListNode tmp = head;
        while(tmp.getNext()!=null){
            tmp = tmp.getNext();
        }
        tmp.setNext(e);
    }

}
