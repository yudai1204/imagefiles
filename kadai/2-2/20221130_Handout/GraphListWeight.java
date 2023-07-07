import java.util.*;

public class GraphListWeight {
    // グラフのクラス
    int numV;
    LinkedList<Edge> [] adj;
    
    // 辺のクラス EdgeクラスをLinkedListで使ったが，そのEdgeクラスの定義．
    static class Edge {
        int node;
        int next;
        int weight;

        public Edge(int node, int next, int weight) {
            this.node = node;
            this.next = next;
            this.weight = weight;
        }
    }

    public GraphListWeight(int numV) {
        this.numV = numV;
        adj = new LinkedList[numV];// 頂点数numVerticesの数だけLinkedListを作る．
        for (int i = 0; i < numV ; i++) {
            adj[i] = new LinkedList<Edge>(); // 初期化
        }
    }

    public void addEdge(int node, int next, int weight) {
        Edge edge = new Edge(node, next, weight);
        adj[node].add(edge); // nodeを始点としたLinkedリストにedgeの情報を加える．
    }

    public void printG(){
        for (int i = 0; i < numV ; i++) {
            LinkedList<Edge> list = adj[i];
                System.out.print(i);
            for (int j = 0; j < list.size() ; j++) {
                System.out.print(" -> " + list.get(j).next + ":" +  list.get(j).weight);
            }
                System.out.println();
        }
    }

}