public class GraphMatrixWeight {
    public int adj[][];
    public int numV;
  
    // コンストラクタ 初期化
    public GraphMatrixWeight(int numV) {
      this.numV = numV;
      adj = new int[numV][numV];
    }
  
    // 辺の追加
    public void addEdge(int i, int j, int k) {
      adj[i][j] = k;
    }
  
    // 行列の表示
    public void printG(){
      StringBuilder s = new StringBuilder();
      for (int i = 0; i < numV; i++) {
        s.append(i + ": ");
        for (int j = 0; j < numV; j++) {
          s.append(adj[i][j] + " ");
        }
        s.append("\n");
      }
      System.out.println(s); 
    }

  }