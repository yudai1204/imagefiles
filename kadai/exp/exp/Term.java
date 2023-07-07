import java.util.*;

// 式の項（term）を表すクラス

public class Term extends Node {

    public String toString() {
        return "Term";
    }

    // 指定された状態（state）での式の値を求めるメソッド
    double eval(Map<String, Expression> state) {
        // 処理内容を考えて
        // ここに実装する
        double value = childList.get(0).eval(state); //0番目のFactorを計算
        //奇数番目にoperator(*or/)、偶数番目にFactorがあるはず
        for(int i=1; i < childList.size(); i+= 2) {
            Token  t  = (Token)childList.get(i); // * か / か ^ のはず
            Factor t2 = (Factor)childList.get(i+1); // Factorのはず
            if (t.str.equals("*")) {
                value *= t2.eval(state);
            } else if(t.str.equals("/")) {
                value /= t2.eval(state);
            }else{
                value = Math.pow(value, t2.eval(state));
            }
        }
        return value;
    }
}
