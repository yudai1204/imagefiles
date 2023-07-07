public class CalcMain {
    public static void main(String[] args) {
        Calculator calc = new Calculator("data.txt");
        long start = System.nanoTime();
        calc.createNodes(3);
        System.out.println("SUM" + calc.getSum());
        long end = System.nanoTime();
        System.out.println("Time:" + (end -start) / 1000000f + "ms");
    }
}