// 式の構文解析の処理を担当するクラス

public class Parser {
    // フィールド：トークンを管理する字句解析器
    Tokenizer tokenizer;

    // コンストラクタ
    public Parser(Tokenizer t) {
        tokenizer = t;
    }

    // 次に続く式（expression）を構文解析して取得する
    Expression parseExpression() {
        Expression exp = new Expression();
        Term term1 = parseTerm();  // まずTermを取得し
        exp.childList.add(term1);  // 1つめの子にする
        while (true) {  // 0回以上の繰り返しの部分
            Token t = tokenizer.nextToken();
            if (t == null) {
                break;
            }
            if (t.str.equals("+") || t.str.equals("-") ) {  // +, -が続く場合
                exp.childList.add(t);  // この演算子を次の子にして
                Term term2 = parseTerm();
                exp.childList.add(term2);  // 続くTermをその次の子にする
            }  else {
                tokenizer.backToken();  // Token tは読まなかったことにする
                break;
            }
        }
        return exp;
    }

    // 次に続く式の項（term）を構文解析して取得する
    Term parseTerm() {
        Term term = new Term();
        Factor factor1 = parseFactor();  // まずFactorを取得し
        term.childList.add(factor1);  // 1つめの子にする
        while (true) {  // 0回以上の繰り返しの部分
            Token t = tokenizer.nextToken();
            if (t == null) {
                break;
            }
            if (t.str.equals("*") || t.str.equals("/") || t.str.equals("^") ) {  // *, / , ^ が続く場合
                term.childList.add(t);  // この演算子を次の子にして
                Factor factor2 = parseFactor();
                term.childList.add(factor2); // 続くFactorをその次の子にする
            } else {
                tokenizer.backToken();  // Token tは読まなかったことにする
                break;
            }
        }
        return term;
    }

    // 次に続く式の因子（factor）を構文解析して取得する
    Factor parseFactor() {
        Factor factor = new Factor();
        Token t = tokenizer.nextToken();  // まずTokenを取得し
        factor.childList.add(t);  // 1つめの子にする
        if (t.str.equals("(")) {  // 括弧に囲まれたexpressionの場合
            Expression exp = parseExpression();  // 括弧の次のExpressionを取得し
            factor.childList.add(exp);  // このExpressionを次の子にして
            t = tokenizer.nextToken();
            if (!t.str.equals(")")) {
                System.out.println("構文エラー：)がありません");
                System.exit(0);
            }
            factor.childList.add(t);  // 閉じ括弧をその次の子にする
        }
        else if (t.str.equals("sqrt") || t.str.equals("log")) {  // log, sqrtの場合
            t = tokenizer.nextToken();
            //次のtokenが(出なかった場合は終了する
            if(!t.str.equals("(")){
                System.out.println("構文エラー：(がありません");
                System.exit(0);
            }
            factor.childList.add(t);    //括弧を子にする
            Expression exp = parseExpression();  // 括弧の次のExpressionを取得し
            factor.childList.add(exp);  // このExpressionを次の子にして
            t = tokenizer.nextToken();
            if (!t.str.equals(")")) {
                System.out.println("構文エラー：)がありません");
                System.exit(0);
            }
            factor.childList.add(t);  // 閉じ括弧をその次の子にする
        }
        return factor;
    }

    // 単体テスト用メインメソッド
    public static void main(String[] args) {
        String s = " x*2 + sqrt(y-1) / 3 ";
        
        Parser parser = new Parser(new Tokenizer(s));
        Expression exp = parser.parseExpression();
        exp.print();
    }
}
