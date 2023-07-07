import java.io.*;
import java.util.*;

public class Calculator {

  List<Integer> dataList = new ArrayList<Integer>();
  List<CalcNode> nodeList = new ArrayList<CalcNode>();
  long sum = 0;

  Calculator(String fileName) {
    try {
      FileInputStream fis = new FileInputStream(fileName);
      InputStreamReader isr = new InputStreamReader(fis);
      BufferedReader br = new BufferedReader(isr);
      String line;
      while ((line = br.readLine()) != null) {
        dataList.add(Integer.parseInt(line));
      }
      br.close();
    } catch (IOException e) {
      e.printStackTrace();
      throw new IndexOutOfBoundsException();
    }
  }

  void createNodes(int n) {
    for (int i = 0; i < n; i++) {
      CalcNode node = new CalcNode(this);
      node.assign(dataList, i, n);
      nodeList.add(node);
      node.start();
    }
  }

  synchronized void addSum(long s) {
    this.sum += s;
  }

  long getSum() {
    try {
      for (CalcNode s : nodeList) {
        s.join();
      }
    } catch (InterruptedException e) {
      e.getStackTrace();
    }
    return this.sum;
  }
}
