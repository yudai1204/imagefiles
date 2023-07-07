import java.util.*;

class WordCounter {
    // 単語に出現回数を対応付ける写像
    Map<String, Integer> countMap;

    // コンストラクタ：カウンタの初期化
    public WordCounter() {
        countMap = new HashMap<String, Integer>();
    }

    // 単語の出現情報を 1 回分追加する
    public void add(String getword) {
        String word = getword.toLowerCase().replaceAll("\\.|!","");
        Integer count = countMap.get(word);
        if (count != null) { // マップに登録済み（最低 1 回は出現済み）の場合は
            int newCount = count.intValue() + 1; // 記録されている回数に１を足して
            countMap.put(word, newCount); // マップに上書き登録する
        } else { // 今まで出現していない単語の場合は
            countMap.put(word, 1); // マップに出現回数 1 と登録する
        }
    }

    // 単語の出現回数を返す
    public int getNumber(String word) {
        Integer count = countMap.get(word);
        if (count != null) {
            return count.intValue();
        } else {
            return 0;
        }
    }

    // 出現した単語のリストを作って返す
    public List<String> getWordList() {
        return new ArrayList<String>(countMap.keySet());
    }

    // 出現回数順にオブジェクトをソートしたリストを作って返す
    public List<String> getSortedWordList() {
        List<String> wordList = getWordList();
        Collections.sort(wordList, new Comparator<String>() {
            public int compare(String word1, String word2) { // 比較基準の定義
                return countMap.get(word2) - countMap.get(word1);
            }
        });
        return wordList;
    }
}