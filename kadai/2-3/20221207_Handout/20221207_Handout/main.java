import java.util.*;

class main {
  public static void main(String[] args) throws java.lang.Exception {

    GraphMatrixWeight g = new GraphMatrixWeight(6);
    g.addEdge(0, 1, 8);
    g.addEdge(0, 4, 3);
    g.addEdge(1, 2, 9);
    g.addEdge(2, 4, 7);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 5, 5);
    g.addEdge(4, 2, 7);
    g.addEdge(4, 3, 4);

    FordFulkerson m = new FordFulkerson();

    // 課題3用 幅優先探索が動くかの確認用
    int p[] = new int[g.adj.length];
    m.bfs(g.adj, 0, 2, p);
    for (int i = 0; i < g.adj.length; i++){
      System.out.println(i + "の親ノード:" + p[i]);
    }
    // 課題3用 幅優先探索が動くかの確認用 (ここまで)

    System.out.println();

    // 課題4用 Ford-Fulkerson法の動作
    // 課題４では，以下の二行のコメントアウトを外すこと
//    int maxflow = m.fordFulkerson(g.adj, 0, 5);
//    System.out.println("最大流は" + maxflow);
    // 課題4用 Ford-Fulkerson法の動作 (ここまで)

  }
}
