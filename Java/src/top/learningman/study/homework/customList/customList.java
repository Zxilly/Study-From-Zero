package top.learningman.study.homework.customList;

public class customList {
    customListNode head;

    public customList(){
        this.head=null;
    }

    public customList(int...data){
        this.head = new customListNode(data[0]);
        for(int i=1;i<data.length;i++){
            this.cPush(new customListNode(data[i]));
        }
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
    }

    public void cPush(customListNode e){
        customListNode tmp = head;
        if(head == null){
            head = e;
            return;
        }
        while(tmp.getNext()!=null){
            tmp = tmp.getNext();
        }
        tmp.setNext(e);
    }

    public customListNode cPop(){
        customListNode tmp = head;
        if(tmp.getNext()==null){
            this.head = null;
            return tmp;
        }
        while(tmp.getNext().getNext()!=null){
            tmp = tmp.getNext();
        }
        customListNode tmp2 = tmp.getNext();
        tmp.setNext(null);
        return tmp2;
    }

    public boolean isEmpty(){
        return this.head==null;
    }

    public customList reverse(){
        customList tmp = new customList();
        while(!this.isEmpty()){
            tmp.cPush(this.cPop());
        }
        return tmp;
    }

    @Override
    public String toString() {
        StringBuilder data = new StringBuilder("customList{");
        customListNode tmp = head;
        while (tmp.getNext()!=null){
            data.append(tmp.getData()).append(",");
            tmp = tmp.getNext();
        }
        data.append(tmp.getData()).append("}");
        return data.toString();
    }
}
