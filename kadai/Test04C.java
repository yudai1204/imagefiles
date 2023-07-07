import my_util.*;

class Test04C {
    public static void main(String[] args) {
        String str;
        // デフォルト文字コードでの読み書き
        str = FileUtil.readTextFile("input_default.txt");
        FileUtil.writeTextFile(str, "output_default.txt");
        // SJIS のファイルを読んで UTF-8 でファイル出力
        str = FileUtil.readTextFile("input_sjis.txt", "SJIS");
        FileUtil.writeTextFile(str, "output_utf8.txt", "UTF-8");
        // UTF-8 のファイルを読んで SJIS でファイル出力
        str = FileUtil.readTextFile("input_utf8.txt", "UTF-8");
        FileUtil.writeTextFile(str, "output_sjis.txt", "SJIS");
    }
}