import java.util.*;

class Test05A {

    public static void main(String[] args) {
        List<Integer> list = new ArrayList<Integer>();
        long start = System.nanoTime();
        //
        // list の末尾に 1 から 10000 までの整数を順に追加していく
        //
        long end = System.nanoTime();
        System.out.println(list);
        System.out.println("Time:" + (end - start) / 1000000.0 + "ms");
    }
}
