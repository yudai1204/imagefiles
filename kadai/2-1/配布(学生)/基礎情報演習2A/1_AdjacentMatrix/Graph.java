public class Graph {
    private int adjMatrix[][];
    private int numVertices;
  
    // コンストラクタ 初期化
    public Graph(int numVertices) {
      this.numVertices = numVertices;
      adjMatrix = new int[numVertices][numVertices];
    }
  
    // 辺の追加
    public void addEdge(int i, int j, int k) {
      adjMatrix[i][j] = k;
      // adjMatrix[j][i] = k;
    }
  
    // 辺の削除
    public void removeEdge(int i, int j) {
      adjMatrix[i][j] = 0;
      // adjMatrix[j][i] = 0;
    }
  
    // 行列の表示
    public String toString() {
      StringBuilder s = new StringBuilder();
      for (int i = 0; i < numVertices; i++) {
        s.append(i + ": ");
        for (int j : adjMatrix[i]) {
          s.append(j + " ");
        }
        s.append("\n");
      }
      return s.toString();
    }
  }

