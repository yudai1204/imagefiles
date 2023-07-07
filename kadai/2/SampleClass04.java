class SampleClass04 {
    public static void main(String[] args) {
        Person taro = new Person("太郎");
        Person hanako = new Person();
        hanako.name = "花子";
        for (int i=0; i<100; i++) {
        taro.walk(); hanako.walk(2);
        }
        taro.print();
        hanako.print();
        }
}
