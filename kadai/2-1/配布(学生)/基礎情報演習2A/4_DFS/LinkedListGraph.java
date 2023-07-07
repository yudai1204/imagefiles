import java.util.*;

public class LinkedListGraph {

    // グラフのクラス
    static class Graph {
        int numVertices;
        LinkedList<Integer> [] adj;
        boolean done[]; // ここはBFSと異なる

        Graph(int numVertices) {
            this.numVertices = numVertices;
            adj = new LinkedList[numVertices];
            done = new boolean[numVertices]; // ここはBFSと異なる
            for (int i = 0; i < numVertices ; i++) {
                adj[i] = new LinkedList<>(); 
            }
        }

        public void addEdge(int node, int next) {  
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


  // DFS recursive
  void DFSre(int u) {
    // * 頂点uに訪問したという印をつける
    done[u] = true;
    System.out.print(u + ">"); // 訪問した箇所を記述
    // * 頂点uに隣接する要素を取り出す(隣接頂点のリストuvEを生成)
    Iterator<Integer> iterator = adj[u].listIterator(); // 頂点uの隣接要素を取り出す
    while (iterator.hasNext()) { // * 隣接する辺がまだあるか？
        // * 隣接要素があり，それをvとする
        int v = iterator.next();
        // * まだvがまだ訪問されていないなら・・・
        if (!done[v]) { 
            DFSre(v); // * 再帰的に探索
        }
    }
  }





    }

}