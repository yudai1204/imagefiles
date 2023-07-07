public class Queue {
    int[] a;
    int head,tail;
    Queue(){
        a = new int[100];
        head = tail = 0;
    }
    void enqueue(int i){
        a[++tail] = i;
    }
    int dequeue(){
        return a[++head];
    }
    boolean isEmpty(){
        return (head == tail)?true:false;
    }
}
