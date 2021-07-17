package top.learningman.homework.customSet;

import java.util.ArrayList;
import java.util.Iterator;

public class customSet {
    private final ArrayList<Integer> _data = new ArrayList<>();

    public boolean isExist(int i){
       return  this._data.contains(i);
    }

    public void add(int i){
        if(!this.isExist(i)){
            this._data.add(i);
        }
    }

    public boolean remove(int i){
        if(this.isExist(i)){
            this._data.remove((Integer) i);
            return true;
        } else {
            return false;
        }
    }

    public Iterator<Integer> iterator(){
        return this._data.listIterator();
    }

    public void print(){
        for(int i:this._data){
            System.out.print(i+"\t");
        }
        System.out.print("\n");
    }
}
