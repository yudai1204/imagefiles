public class MyList {
    ListNode head = null;

    void add(int x) {
        if (this.head == null) {
            this.head = new ListNode(x);
        } else {
            ListNode p = this.head;
            for(;p.next != null;) {
                p = p.next;
            }
            p.next = new ListNode(x);
        }
    }

    void print() {
        ListNode p = head;
        while (p != null) {
            System.out.print(p.key + " "); // 「print」メソッドは改行しない
            p = p.next;
        }
        System.out.println(); // 最後に 1 回改行する
    }
    int indexOf(int x){
        int i=0;
        ListNode p = this.head;
        for(;p.key != x;){
            if(p == null || p.next == null){
                return -1;
            }
            p = p.next;
            i++;
        }
        return i;
    }
    int get(int n){
        ListNode p = this.head;
        for(;n > 0;n--){
            if(p == null){
                throw new IndexOutOfBoundsException();
            }
            p = p.next;
        }
        return p.key;
    }
}
