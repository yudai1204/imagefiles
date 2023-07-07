import java.util.*;

// 式（expression）を表すクラス

public class Expression extends Node {

    public String toString() {
        return "Expression";
    }

    // 指定された状態（state）での式の値を求めるメソッド
    double eval(Map<String, Expression> state) {
        // System.out.println("exp");
        double value = childList.get(0).eval(state);  // 1つめの子であるTermの値を求める

        for (int i = 1; i < childList.size(); i += 2) {
            Token t = (Token)childList.get(i);  // "+" か "-" のはず
            Term t2 = (Term)childList.get(i+1);  // Termのはず
            if (t.str.equals("+")) {
                value += t2.eval(state);
            } else {
                value -= t2.eval(state);
            }
        }

        return value;
    }
}
