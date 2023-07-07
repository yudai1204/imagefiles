import java.util.*;
import java.io.*;
import java.util.Random;

class Markov {
    public static void main(String[] args) {
        List<Chain> list = new ArrayList<Chain>();
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

        String[] split = str.split(" ");
        for (int i = 0; i < split.length-1; i++) {
            boolean flag = true;
            for(Chain l: list){
                if(l.getName().equals(split[i])){
                    flag = false;
                    l.addWord(split[i+1]);
                    break;
                }
            }
            if(flag){
                list.add(new Chain(split[i],split[i+1]));
            }
        }
        
        for(Chain l:list){
            l.getsort();
        }

        Chain first = list.get(0);
        for(Chain l:list){
            if(l.getCount() > first.getCount()){
                first = l;
            }
        }
        for(int i=0; i<10; i++){
            System.out.println(first.getName());
            String nxt = first.getMarcov();
            for(Chain l:list){
                if(nxt == l.getName()){
                    first = l;
                    break;
                }
            }
        }
        

    }
}

class Chain{
    String name;
    int sum;
    WordCounter counter; // カウンタの初期化
    Random rand;
    List<String> wordList;
    Chain(String n){
        name = n.toLowerCase().replaceAll("\\.|!","");
        rand = new Random();
        counter = new WordCounter();
        wordList = new ArrayList<String>();
        sum = 0;
    }
    Chain(String n, String w){
        name = n.toLowerCase().replaceAll("\\.|!","");
        rand = new Random();
        counter = new WordCounter();
        wordList = new ArrayList<String>();
        sum = 0;
        this.addWord(w);
    }
    String getName(){
        return name;
    }
    void addWord(String n){
        counter.add(n);
        wordList.add(n);
        sum++;
    }
    void getsort(){
        wordList = counter.getSortedWordList();
    }
    int getCount(){
        return sum;
    }
    String getMarcov(){
        int val = rand.nextInt(sum+1);
        for(int i = 0; i<wordList.size(); i++){
            String w = wordList.get(i);
            if(counter.getNumber(w) >= val){
                return w;
            }
            val -= counter.getNumber(w);
        }
        return wordList.get(0);
    }
    void print(String w) {
        for (int i = 0; i < ((wordList.size()>20)?20:wordList.size()); i++) {
            System.out.printf("%4d\t%s\n", counter.getNumber(w), w);
        }
    }
}