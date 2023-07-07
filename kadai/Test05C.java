import java.util.*;
import java.io.*;

class Test05C {
    public static void main(String[] args) {
        WordCounter counter = new WordCounter(); // カウンタの初期化
        String str = new String();
        try {
            FileInputStream fis = new FileInputStream("alice.txt");
            InputStreamReader isr = new InputStreamReader(fis, "SJIS");
            BufferedReader br = new BufferedReader(isr);
            String line;
            while ((line = br.readLine()) != null) {
                str += line + "\n";
            }
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        String[] split = str.split("\\s+");
        for (int i = 0; i < split.length; i++) {
            counter.add(split[i]); // 単語を 1 つずつカウンタに追加（add）
        }
        List<String> wordList = counter.getSortedWordList();
        for (int i = 0; i < ((wordList.size()>20)?20:wordList.size()); i++) {
            String w = wordList.get(i);
            System.out.printf("%4d\t%s\n", counter.getNumber(w), w);
        }
    }
}