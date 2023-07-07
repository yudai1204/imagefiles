class Jikkou1{
    public static void main(String[] args){
        Saifu mySaifu = new Saifu();
        int money = mySaifu.getOkane();
        money += 5000;
        mySaifu.setOkane(money);
        System.out.println("okane=" + mySaifu.getOkane());
    }
}