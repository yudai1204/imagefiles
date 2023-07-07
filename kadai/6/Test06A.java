public class Test06A {
  public static void main(String[] args) {
    Counter counter = new Counter();
    CountThread thread1 = new CountThread(counter);
    CountThread thread2 = new CountThread(counter);
    thread1.start();
    thread2.start();
    try {
        thread1.join();
        thread2.join();
    } catch (Exception e) {
        e.printStackTrace();
    }
    System.out.println("final count=" + counter.getCount());
  }


}
