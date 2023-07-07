class Test02A {
    public static void main(String[] args) {
        Stack s = new Stack(); // スタックオブジェクトを生成、初期化
        for (int i = 1; i <= 10; i++) {
            s.push(i); // 1, 2, …, 10 の順にスタックに整数を push
        }
        while (!s.isEmpty()) { // スタックが空でない間くり返す
            int n = s.pop();
            System.out.println(n);
        }
        Queue q = new Queue(); // キューオブジェクトを生成、初期化
        for (int i = 1; i <= 10; i++) {
            q.enqueue(i); // 1, 2, …, 10 の順にキューに整数を追加
        }
        while (!q.isEmpty()) { // キューが空でない間くり返す
            int n = q.dequeue();
            System.out.println(n);
        }
    }
}
