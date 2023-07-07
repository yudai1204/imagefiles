import java.io.*;
import java.util.*;

public class ExpSimple {
    // フィールド：変数名と数値の対応表（状態，state）
    static Map<String, Integer> state = new HashMap<String, Integer>();

    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(
                    new InputStreamReader(System.in)); // 標準入力
            String line;
            while ((line = br.readLine()) != null) { // 対話的な入出力のループ
                String[] params = line.split("\\s+");
                if (line.equals("")) { // 空行の場合
                    continue;
                }
                if (line.equals("exit")) { // exit コマンド：プログラム終了
                    break;
                }
                if (params[0].equals("set")) { // set コマンド：変数と数値の対応付け
                    // line から変数名の文字列と数値の文字列を取り出す
                    // 変数名の文字列が英字で始まる英数字列かどうか確認
                    // 数値の文字列を int 型の値に変換
                    // マップ（state）に変数名と数値の関係を設定する
                    if(!params[1].matches("[a-zA-Z][a-zA-Z0-9]*")){
                        System.out.println("変数名は英数字のみ入力してください");
                        continue;
                    }
                    state.put(params[1], Integer.parseInt(params[2]));
                    System.out.println("変数 "+params[1]+" に "+params[2]+" を割り当てました");
                } else if (line.equals("show")) { // show コマンド
                    //
                    // マップ（state）の記憶内容を出力
                    //
                    for(Map.Entry<String, Integer> entry : state.entrySet()){
                        System.out.println(entry.getKey() +"\t" + entry.getValue());
                    }
                } else {
                    // line を変数名と考えて、マップ（state）から対応する数値を取得
                    // この際、直接 int に代入するのでなく、いったん Integer 型変数に
                    // 代入し、それが null と等しければ未定義メッセージを出力する
                    // そうでなければその値（整数値）を出力する
                    boolean flag = true;
                    for(Map.Entry<String, Integer> entry : state.entrySet()){
                        if(entry.getKey().equals(line)){
                            System.out.println(entry.getValue());
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        System.out.println("変数 "+line+" は未定義です");
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}