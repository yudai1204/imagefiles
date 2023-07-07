import java.util.*;

// 構文木のノードを表す抽象クラス

public abstract class Node {
    // フィールド：子ノードのリスト
    List<Node> childList = new ArrayList<Node>();

    // 指定された状態（state）での式の値を求めるメソッド
    abstract double eval(Map<String, Expression> state);

    // 構文木を出力するメソッド
    void print() {
        print(0);
    }

    // levelの分だけ字下げして構文木を出力する
    void print(int level) {
        for (int i = 0; i < level; i++) {
            System.out.print("----");
        }
        System.out.println(this);
        for (Node child : childList) {  // それぞれの子を
            child.print(level + 1);  // 字下げを増やして出力する
        }
    }

    String getType(){
        return this.toString();
    }
}
