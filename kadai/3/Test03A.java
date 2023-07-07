public class Test03A {
    public static void main(String[] args) {
        Chokin a = new Chokin();
        a.addOkane(5000);
        Chokin b = a;
        b.addOkane(30000);
        a.print();
        b.print();
    }
}
