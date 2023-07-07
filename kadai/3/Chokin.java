public class Chokin {
    int okane;

    Chokin() {
        okane = 10000;
    }

    void addOkane(int i) {
        okane += i;
    }

    void print() {
        System.out.println(okane + "yen");
    }
}
