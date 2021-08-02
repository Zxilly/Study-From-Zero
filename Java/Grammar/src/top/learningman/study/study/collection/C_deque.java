package top.learningman.study.study.collection;

import java.util.Deque;
import java.util.LinkedList;

public class C_deque {
    // Deque 继承自 Queue， 使用中更应该考虑其本身的 API
    /*
    	Queue	                                        Deque
        添加元素到队尾	        add(E e) / offer(E e)	    addLast(E e) / offerLast(E e)
        取队首元素并删除	    E remove() / E poll()	    E removeFirst() / E pollFirst()
        取队首元素但不删除	    E element() / E peek()	    E getFirst() / E peekFirst()
        添加元素到队首	        无	                        addFirst(E e) / offerFirst(E e)
        取队尾元素并删除	    无	                        E removeLast() / E pollLast()
        取队尾元素但不删除	    无	                        E getLast() / E peekLast()
     */
    public static void main(String[] args) {
        Deque<String> deque = new LinkedList<>();
        deque.offerLast("A"); // A
        deque.offerLast("B"); // A <- B
        deque.offerFirst("C"); // C <- A <- B
        System.out.println(deque.pollFirst()); // C, 剩下A <- B
        System.out.println(deque.pollLast()); // B, 剩下A
        System.out.println(deque.pollFirst()); // A
        System.out.println(deque.pollFirst()); // null
    }
}
