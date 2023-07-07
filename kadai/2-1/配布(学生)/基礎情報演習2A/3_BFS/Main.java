import java.util.*;

public class Main {
      public static void main(String[] args) {
            LinkedListGraph.Graph g = new LinkedListGraph.Graph(4);
            g.addEgde(0, 1);
            g.addEgde(0, 2);
            g.addEgde(1, 3);
            g.addEgde(1, 2);
            g.addEgde(2, 3);
            g.addEgde(3, 0);
            g.printG();

            System.out.println("BFS");
            g.BFS(2);

      }
}