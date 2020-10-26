package top.learningman.study.homework.customList;

public class customListNode {
    private int data;
    private customListNode next;

    public customListNode(){
        this.data=0;
        this.next=null;
    }

    public customListNode(int data){
        this.data = data;
        this.next = null;
    }

    public customListNode(int data, customListNode next){
        this.data = data;
        this.next = next;
    }

    public int getData() {
        return data;
    }

    public void setData(int data) {
        this.data = data;
    }

    public customListNode getNext() {
        return next;
    }

    public void setNext(customListNode next) {
        this.next = next;
    }

    @Override
    public String toString(){
        return this.data+"";
    }
}
