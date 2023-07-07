import java.util.*;

public class LinkedListGraph {
    // * 重み付き連結リストの場合: ここにEdgeクラスを作り，変数をnode, next, weightを持つようにする．
    static class Edge{
        public int node;
        public int next;
        public int weight;
        Edge(int node, int weight, int next){
            this.node = node;
            this.weight = weight;
            this.next = next;
        }
    }
    // グラフのクラス
    static class Graph {
        int numVertices;
        LinkedList<Edge> [] adj; // * 重み付き連結リストの場合: Integerではなく，Edgeクラスを変数にもつリストを作る．

        Graph(int numVertices) {
            this.numVertices = numVertices;
            adj = new LinkedList[numVertices];// 頂点数numVerticesの数だけLinkedListを作る．
            for (int i = 0; i < numVertices ; i++) {
                adj[i] = new LinkedList<>(); // adjの初期化
            }
        }

        public void addEdge(int node, int next, int weight) {  // * 重み付き連結リストの場合: 引数にweightも加わる．
            // * 重み付き連結リストの場合: 引数にnode, next, weightを持つEdgeクラスのインスタンスを作る．
            adj[node].add(new Edge(node, weight, next)); // nodeを始点としたLinkedリストにnextの情報を加える．// * 重み付き連結リストの場合: nextではなく， Edgeクラスのインスタンスの情報を与える
        }

        public void printG(){
            for (int i = 0; i < numVertices ; i++) {
                LinkedList<Edge> list = adj[i];
                    System.out.print(i);
                for (int j = 0; j < list.size() ; j++) {
                    //System.out.print(" -> " + list.get(j)); // * 重み付き連結リストの場合: 下記に書き換える． System.out.print(" -> " + list.get(j).next + ":" +  list.get(j).weight);
                    System.out.print(" -> " + list.get(j).next + ":" +  list.get(j).weight);
                }
                    System.out.println();
            }
        }
    }
}
