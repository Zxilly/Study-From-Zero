package top.learningman.study.homework.customSet;

import java.util.Iterator;

public class customSetOperator {
    public static customSet union(customSet a,customSet b){ //并集
        customSet c = new customSet();
        for (Iterator<Integer> it = a.iterator(); it.hasNext(); ) {
            int i = it.next();
            c.add(i);
        }
        for (Iterator<Integer> it = b.iterator(); it.hasNext(); ) {
            int i = it.next();
            if (!c.isExist(i)){
                c.add(i);
            }
        }
        return c;
    }

    public static customSet intersection(customSet a,customSet b){ //交集
        customSet c = new customSet();
        for (Iterator<Integer> it = a.iterator(); it.hasNext(); ) {
            int i = it.next();
            if (b.isExist(i)){
                c.add(i);
            }
        }
        return c;
    }
}
