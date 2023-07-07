public class Test03C {
    public static void main(String[] args) {
        MyList list = new MyList(); // リストオブジェクトを生成、初期化
        for (int i = 1; i <= 10; i++) {
            list.add(i * 100); // リスト末尾に 100, 200, …, 1000 の順に追加
        }
        list.print(); // リストの内容を出力 100 200 … 1000 と出力されるはず
        System.out.println(list.indexOf(500)); // 4 になるはず
        System.out.println(list.indexOf(999)); // -1 になるはず
        System.out.println(list.get(5)); // 600 になるはず
        System.out.println(list.get(15)); // Exception が発生するはず
    }
}
