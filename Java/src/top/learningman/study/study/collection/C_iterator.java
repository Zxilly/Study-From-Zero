package top.learningman.study.study.collection;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class C_iterator {
    public static void main(String[] args) {
        // 能在类中执行，是因为这是一个 static 函数. 同时，命名也是 main
        // 为了与之适应，应该使用 static 的内部类。
        ReverseList<String> rlist = new ReverseList<>();
        rlist.add("Apple");
        rlist.add("Orange");
        rlist.add("Pear");
        for (String s : rlist) {
            System.out.println(s);
        }
    }

    static class ReverseList<T> implements Iterable<T> {

        private final List<T> list = new ArrayList<>();

        public void add(T t) {
            list.add(t);
        }

        @Override
        public Iterator<T> iterator() {
            return new ReverseIterator(list.size());
        }

        class ReverseIterator implements Iterator<T> {
            int index;

            ReverseIterator(int index) {
                this.index = index;
            }

            @Override
            public boolean hasNext() {
                return index > 0;
            }

            @Override
            public T next() {
                index--;
                return ReverseList.this.list.get(index);
            }
        }
    }
}
