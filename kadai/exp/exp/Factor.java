import java.util.*;

// 式の因子（factor）を表すクラス

public class Factor extends Node {

    public String toString() {
        return "Factor";
    }

    // 指定された状態（state）での式の値を求めるメソッド
    double eval(Map<String, Expression> state) {
        // 処理内容を考えて
        // ここに実装する
        if(childList.size() > 3){
            //logかsqrtのとき
            if(childList.get(0).getType().equals("name(sqrt)")){
                //sqrtのとき
                return Math.sqrt(childList.get(2).eval(state));
            }else{
                //logのとき
                return Math.log10(childList.get(2).eval(state));
            }
        }else if(childList.size() == 3){
            //カッコのある式のとき
            return childList.get(1).eval(state);
        }else{
            //因子がカッコがない場合(Tokenのみの場合)
            return childList.get(0).eval(state);
        }
    }
}
