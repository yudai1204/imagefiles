public class Stack {
    int[] a;
    int top;
    Stack(){
        a=  new int[100];
        top = 0;
    }
    void push(int i){
        if(top < 100) a[top++] = i;
    }
    int pop(){
        return (top > 0)?a[--top]:null;
    }
    boolean isEmpty(){
        return (top == 0)?true:false;
    }

}
