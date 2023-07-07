import java.util.List;

public class CalcNode extends Thread {
    List<Integer> dataList;
    int myId;
    int numNodes;
    Calculator calc;

    CalcNode(Calculator calc) {
        this.calc = calc;
    }

    void assign(List<Integer> list, int i, int n) {
        this.dataList = list;
        this.myId = i;
        this.numNodes = n;
    }

    public void run() {
        long sum = 0;
        int numData = this.dataList.size();
        long start = System.nanoTime();

        for (int i = this.myId * numData/ this.numNodes;i < (this.myId + 1) * numData/ this.numNodes; i++) {
            sum += this.dataList.get(i);
            try {
                Thread.sleep(1);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        calc.addSum(sum);
        long end = System.nanoTime();
        System.out.println("ThreadTime:" + (end -start) / 1000000f + "ms");
    }
}
