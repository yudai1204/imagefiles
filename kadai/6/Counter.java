class Counter {

    int count = 0;

    synchronized void countUp() {
        count += 1;
    }

    int getCount() {
        return count;
    }
}
