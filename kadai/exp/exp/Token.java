import java.util.*;

// 式を構成する最小単位である字句（トークン）を表すクラス

public class Token extends Node {
    // フィールド：このトークンの文字列
    String str;
    // フィールド：このトークンの種類を表す文字列（"number", "name", "operator"）
    String kind;
    // フィールド：kind=numberの場合，その数値を入れる
    double value;

    // コンストラクタ
    public Token(String s) {
        str = s;
    }

    public String toString() {
        return kind + "(" + str + ")";
    }

    // 指定された状態（state）での式の値を求めるメソッド
    double eval(Map<String, Expression> state) {
        // 処理内容を考えて
        // ここに実装する
        //値が入っていた場合、その値を返す
        if( kind.equals("number") ){
            return value;
        }
        //変数が入っていた場合、式を取得して再帰させる
        else if( kind.equals("name") ){
            Expression exp = state.get(str);
            if(exp == null){
                throw new IllegalStateException();
            }
            return exp.eval(state);
        }
        return 0;
    }
}
