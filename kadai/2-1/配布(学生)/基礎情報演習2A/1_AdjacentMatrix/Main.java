class Main {
  public static void main(String args[]) {
      Graph g = new Graph(9);
  
      g.addEdge(0, 1, 8);
      g.addEdge(0, 4, 3);
      g.addEdge(1, 2, 9);
      g.addEdge(2, 4, 7);
      g.addEdge(2, 5, 2);
      g.addEdge(3, 5, 5);
      g.addEdge(4, 2, 7);
      g.addEdge(4, 3, 4);
  
      System.out.print(g.toString());
    }
}
