import java.util.*;

// 式の字句解析の処理を担当するクラス

public class Tokenizer {
    // フィールド：入力に含まれるトークンのリスト
    List<Token> tokenList = new ArrayList<Token>();
    // フィールド：次に読むべきトークンの位置
    int nextIndex = 0;

    // コンストラクタ：最初に入力文字列を字句解析し，トークンのリストに分けておく
    public Tokenizer(String line) {
        char[] chars = line.toCharArray();
        int pos = 0;  // 文字配列charsの中でどの位置の文字に着目しているか

        while (pos < chars.length) {
            if (chars[pos] == ' ') {  // 空白は読み飛ばす
                pos++;
            } else if (Character.isDigit(chars[pos]) || chars[pos] == '.') {  // 数字から始まる数値トークンの抽出
                int posEnd = pos + 1;
                while (posEnd < chars.length && (Character.isDigit(chars[posEnd]) || chars[posEnd] == '.')) {
                    posEnd++;
                }
                String s = new String(chars, pos, posEnd - pos);  // posからposEndの範囲の文字列を抽出する
                Token t = new Token(s);
                t.kind = "number";
                t.value = Double.parseDouble(s);
                tokenList.add(t);
                pos = posEnd;
            } else if (Character.isLetter(chars[pos])) {  // 英字から始まる名前トークンの抽出
                int posEnd = pos + 1;
                while (posEnd < chars.length && (Character.isLetter(chars[posEnd]) || Character.isDigit(chars[posEnd]))) {
                    posEnd++;
                }
                String s = new String(chars, pos, posEnd - pos);  // posからposEndの範囲の文字列を抽出する
                Token t = new Token(s);
                t.kind = "name";
                tokenList.add(t);
                pos = posEnd;
            } else {  // 数値トークンと名前トークン以外は1文字で1トークンと想定
                int posEnd = pos + 1;
                String s = new String(chars, pos, posEnd - pos);
                Token t = new Token(s);
                t.kind = "operator";  // +, -, *, /, (, )
                tokenList.add(t);
                pos = posEnd;
            }
        }
    }

    // 次のトークンを返すメソッド
    public Token nextToken() {
        if (nextIndex < tokenList.size()) {
            return tokenList.get(nextIndex++);
        } else {
            return null;
        }
    }

    // 次に読むトークンの位置を1つ戻す（直前のnextTokenメソッド実行をキャンセル）
    public void backToken() {
        if (nextIndex > 0) {
            nextIndex--;
        }
    }

    // 単体テスト用メインメソッド
    public static void main(String[] args) {
        String s = " x*2 + sqrt(y-1) / 3 ";
        
        Tokenizer tokenizer = new Tokenizer(s);
        while (true) {
            Token t = tokenizer.nextToken();
            if (t == null) break;
            System.out.println(t);
        }
    }
}
