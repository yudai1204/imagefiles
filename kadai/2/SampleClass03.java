class SampleClass03 {
    public static void main(String[] args) {
        Person taro = new Person();
        for (int i = 0; i < 100; i++) {
            taro.walk();
        }
        System.out.println(taro.getSteps() + "steps");
    }
}
