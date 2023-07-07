public class Test02B {
    public static void main(String[] args) {
        Dog akita = new Dog();
        akita.setName(akita.getName()+"-KOU");
        System.out.println(akita.getName().length());
        System.out.println(akita.getName().toLowerCase());
        System.out.println(akita.getName().replace("HA","PO"));
        System.out.println(akita.getName().split("-")[0]);
    }
}
