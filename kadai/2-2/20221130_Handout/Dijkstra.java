import java.util.*;

public class Dijkstra {
// フィールド変数の定義
  int numV; // ネットワークの頂点数
  int[][] adjM; //  隣接行列 (課題3で使う)
  LinkedList<GraphListWeight.Edge> [] adjL; // 隣接リスト (課題4で使う)
  boolean[] done; // 訪問したかどうか．trueで訪問済,falseで未訪問 
  boolean[] vertex; // 頂点の参照用
  int[] distance; // 始点からの距離を格納する配列．配列の大きさは頂点数
  int[] parent; // 親ノードを格納する配列．配列の大きさは頂点数
// フィールド変数の定義

// 課題3用のコンストラクタ 配列adjMが引数
  public Dijkstra(int numV, int[][] adjM) {
    this.adjM = adjM; // adjMはDijkstraクラスの変数

    boolean[] done = new boolean[numV]; // 配列doneの生成
    boolean[] vertex = new boolean[numV]; // 配列vertexの生成
    int[] distance = new int[numV]; // 配列distanceの生成
    int[] parent = new int[numV]; // 配列parentの生成
    this.numV = numV; // numVはDijkstraクラスの変数
    this.done = done; // doneはDijkstraクラスの変数
    this.vertex = vertex; // vertexはDijkstraクラスの変数
    this.distance = distance; // distanceはDijkstraクラスの変数
    this.parent = parent; // parentはDijkstraクラスの変数
  }
// 課題3用のコンストラクタ 配列adjMが引数（ここまで）

// 課題4用のコンストラクタ 配列adjLが引数 (課題3と同様につくってみよう)
// オーバーロードするので，名前は上のDijkstraと同じにする．
public Dijkstra(int numV, LinkedList<GraphListWeight.Edge>[] adjL) {
  this.adjL = adjL; // adjMはDijkstraクラスの変数

  boolean[] done = new boolean[numV]; // 配列doneの生成
  boolean[] vertex = new boolean[numV]; // 配列vertexの生成
  int[] distance = new int[numV]; // 配列distanceの生成
  int[] parent = new int[numV]; // 配列parentの生成
  this.numV = numV; // numVはDijkstraクラスの変数
  this.done = done; // doneはDijkstraクラスの変数
  this.vertex = vertex; // vertexはDijkstraクラスの変数
  this.distance = distance; // distanceはDijkstraクラスの変数
  this.parent = parent; // parentはDijkstraクラスの変数
}

//
// 課題4用のコンストラクタ 配列adjLが引数（ここまで）

// dijkstraのメソッド
  public void dijkstra(int s) { // 入力は始点s(source)

// 以下で初期化を行います．
// 配列の初期化はArrays.fill(配列,初期化の値)が便利．
    // 始点からの距離の配列distanceをInt型で扱える範囲の最大値に初期化: 無限大はInteger.MAX_VALUEを使うと便利
    // doneは全て未訪問(false)として初期化
    // 参照用のvertexは全てtrueで初期化
    // 始点s自身の距離は0として初期化
    Arrays.fill(distance, Integer.MAX_VALUE);
    Arrays.fill(done, false);
    Arrays.fill(vertex, true);
    distance[s] = 0;
    int u = s;
// 初期化はここまで

// 擬似コードの while (X!=V){ の部分．while(条件式){ は条件式=trueの場合，処理が行われることに注意．
    while ( !Arrays.equals(done, vertex)) { // doneの中身が全てtrueになり，vertexと等しくなるまで回す．配列同士が等しいかの比較はArrays.equals(配列A,配列B)が便利．

// V=Xの中で，Dの値が最小の頂点をuとする計算を実行する部分．
// 最小の距離minDとその最小距離を与える頂点u=minD_Vertexを与えるアルゴリズムを書く
// for文で地道に探せば良い
//          ここに書く
//
        if(adjM != null){
          for(int i=0;i < adjM[u].length; i++ ){
            if(adjM[u][i] > 0 && distance[i] > adjM[u][i] + distance[u]){
              distance[i] = adjM[u][i] + distance[u];
            }
          }
          int minD = Integer.MAX_VALUE;
          for(int i=0;i < distance.length; i++){
            if(distance[i] < minD && !done[i]){
              u = i;
              minD = distance[i];
            }
          }
        }else if(adjL != null){
          for(GraphListWeight.Edge edge: adjL[u] ){
            if(distance[edge.next] > edge.weight + distance[u]){
              distance[edge.next] = edge.weight + distance[u];
            }
          }
          int minD = Integer.MAX_VALUE;
          for(int i=0;i < distance.length; i++){
            if(!done[i] && distance[i] < minD ){
              u = i;
              minD = distance[i];
            }
          }
        }else{
          throw new IllegalArgumentException();
        }
//
// V=Xの中で，Dの値が最小の頂点をuとする計算を実行する部分（ここまで）
    
// 擬似コードの ① X = X U {u} の部分．
// ここでは，doneのu成分をtrueにすれば良い
//          ここに書く
      done[u] = true;
// 擬似コードの ① X = X U {u} の部分（ここまで）

// 擬似コードの②の部分
// uに接続する各辺について，最短距離distance[v]と，それを与える親ノードparent[v]を求めるメソッドを使う
// 引数を配列adjMにするか，LinkedListにするかを選択するが，メソッド名はfindMinDで共通．<- オーバーロード
// findMinDのメソッドの中身は後で定義
// この部分は変えない
if (adjM != null) { findMinD(u, adjM); } // 隣接行列なら実行
if (adjL != null) { findMinD(u, adjL); } // 隣接リストな実行
// 擬似コードの②の部分

    }
// ここまで擬似コードの while (X!=V){ の部分．

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// print （ここは書き換えない）
// 出力: 0からvまでの距離: d
    for (int i = 0; i < distance.length; i++) {
      System.out.println(String.format(s+ "から" +i+ "までの距離:" +distance[i]));
    }
// 出力: 0からvまでの距離: d (ここまで．)

    System.out.println();
    System.out.println(String.format("始点:" + s));

// 出力: uの親ノード: v
    for (int i = 0; i < distance.length; i++) {
      if (i != s) {
      System.out.println(String.format(i+ "の親ノード: " +parent[i]));
      }
    }
// 出力: uの親ノード: v (ここまで．)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

  }

// 擬似コードの②の部分のメソッド (課題3の隣接行列の場合)
// uに接続する各辺について，最短距離distance[v]と，それを与える親ノードparent[v]を求める．
  public void findMinD(int u,  int[][] adj) { 
      // 全ての頂点vをfor文で回す．v
      // もし，頂点vが未訪問で，かつ，辺(u,v)がつながっているなら・・・
      // もし，距離[u]と辺(u,v)の距離の和が，距離[v]よりも短いなら・・・
      // 距離[v]を更新する
      // vの親親ノードをuに更新する
      for(int v=0; v < adj[0].length; v++){
        if(!done[v] && adj[u][v] > 0 ){
          if(distance[u] + adj[u][v] < distance[v]){
            distance[v] = distance[u] + adj[u][v];
            parent[v] = u;
          }
        }
      }
  }
// 擬似コードの②の部分のメソッド (課題3の隣接行列の場合．ここまで)

// 擬似コードの②の部分のメソッド (課題4の隣接リストの場合)
// uに接続する各辺について，最短距離distance[v]と，それを与える親ノードparent[v]を求める．
// GraphListWeightと課題3の上のメソッド"findMinD"を参考に残りの部分を書いてみよう．
// ．ここに書く．
  public void findMinD(int u,  LinkedList<GraphListWeight.Edge> [] adj) { 
//
//
    for(GraphListWeight.Edge edge :adjL[u]) {
      if(!done[edge.next]){
        if(distance[u] + edge.weight < distance[edge.next]){
          distance[edge.next] = distance[u] + edge.weight;
          parent[edge.next] = u;
        }
      }
    }
//
 }
// 擬似コードの②の部分のメソッド (課題4の隣接リストの場合．ここまで)




}
