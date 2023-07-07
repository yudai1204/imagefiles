public class BankAccount extends Chokin{
    String bank = "TokyoBank";
    void print() {
        System.out.println("bank:" + this.bank);
        super.print();
    }
    BankAccount(String bank) {
        this.bank = bank;
    }
    
}
