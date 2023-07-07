class Person {
    String name;
    int steps = 0;

    Person() {
        name = "名無し";
    }

    Person(String s) {
        name = s;
    }

    void walk() {
        steps++;
    }

    void walk(int i) {
        steps += i;
    }

    int getSteps() {
        return steps;
    }
    void print() {
        System.out.println(name+"は"+getSteps()+"steps");
    }
}
