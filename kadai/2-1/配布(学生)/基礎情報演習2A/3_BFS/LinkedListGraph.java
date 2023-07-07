import java.util.*;

public class LinkedListGraph {

    // グラフのクラス
    static class Graph {
        int numVertices;
        LinkedList<Integer> [] adj; 

        Graph(int numVertices) {
            this.numVertices = numVertices;
            adj = new LinkedList[numVertices];
            for (int i = 0; i < numVertices ; i++) {
                adj[i] = new LinkedList<>(); 
            }
        }

        public void addEgde(int node, int next) {  
            adj[node].add(next); 
        }

        public void printG(){
            for (int i = 0; i < numVertices ; i++) {
                LinkedList<Integer> list = adj[i];
                    System.out.print(i);
                for (int j = 0; j < list.size() ; j++) {
                    System.out.print(" -> " + list.get(j)); 
                }
                    System.out.println();
            }
        }
    // BFS
    void BFS(int s) {

    boolean done[] = new boolean[numVertices]; // 訪問したかのbooleanリスト(サイズは頂点数)
    LinkedList<Integer> Q = new LinkedList(); // キューを連結リストで生成
    
        // ここに正しい順序でコードを入れる
        done[s] = true; //頂点sは訪問した印をつける
        Q.add(s); // 頂点sをキューに入れ初期化
        while (Q.size() != 0) { // キューが空でないなら
            int u = Q.poll();// キューの先頭から頂点uを取り出す（同時に削除)
            Iterator<Integer> iterator = adj[u].listIterator(); // 頂点uの隣接要素を取り出す
            while (iterator.hasNext()) {// 隣接要素がまだあるか？
                int v = iterator.next(); // 隣接要素があり，それをvとする
                if (!done[v]) { 
                    done[v] = true; // vに訪問したという印をつける
                    Q.add(v); // vをQに入れる
                }
            }
            System.out.print(u); // キューから取り出した頂点を書き出す．
            System.out.print(">"); // 次のさす矢印を出力
        }
    }
    }
}
